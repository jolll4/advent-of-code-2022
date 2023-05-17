import networkx as nx
import matplotlib.pyplot as plt

def read_and_strip(file):
    return file.readline().rstrip().rsplit(' ')

def folder_size(G, file, folders_visited):
    row = read_and_strip(file)
    while row[0]:
        if row[1] == 'cd':
            if row[2] == '..':
                folders_visited.pop()
            elif row[2] == '/':
                folders_visited = ['root']
            else:
                folders_visited.append(row[2])
            row = read_and_strip(file)
        elif row[1] == 'ls':
            row = read_and_strip(file)
            while row[0] and row[0] != '$':
                if row[0] == 'dir':
                    G.add_edge(str(folders_visited), str(folders_visited+[row[1]]), weight=0)
                else:
                    G.add_edge(str(folders_visited), str(folders_visited+[row[1]]), weight=int(row[0]))
                row = read_and_strip(file)
    return G

def total_sum(weight_list):
    sum = 0
    for i in weight_list:
        if int(i) < 100000:
            sum += int(i)
    return sum

def recurse_nodes(G, node, weight_list):
    if len(G.adj[node]) > 0:
        sum_of_kids = 0
        count = 0
        for i in G.adj[node]:
            count+=1
            return_sum, weight_list = recurse_nodes(G, node=i, weight_list=weight_list)
            sum_of_kids += G[node][i]["weight"] + return_sum

        weight_list.append(sum_of_kids)
        return sum_of_kids, weight_list
    return 0, weight_list

def smallest_deletable(weight_list):
    used = weight_list[-1]
    weight_list.sort()
    for i in weight_list:
        if 70000000-used+i >= 30000000:
            print("Smallest folder to delete is",i)
            break
    return 0

def node_weights(G):
    sum_of_all, weight_list = recurse_nodes(G, node=str(['root']), weight_list=[])
    print("Weights are", weight_list)
    smallest_deletable(weight_list)
    return total_sum(weight_list)

def make_network(file):
    G = nx.DiGraph()
    return folder_size(G, file, folders_visited=['root'])

def main():
    file = open("day7-input.txt", 'r')
    G = make_network(file)
    print(G)
    print("There are", len(nx.cycle_basis(G.to_undirected())), "loops")
    print("Combined weight is", node_weights(G))
    nx.draw(G, node_size=3)
    plt.show()

main()