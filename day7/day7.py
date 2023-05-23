import networkx as nx
import matplotlib.pyplot as plt

def read_strip_and_split(file):
    return file.readline().rstrip().rsplit(' ')

def read_file_into_graph(G, file, folders_visited):
    row = read_strip_and_split(file)
    while row[0]:
        if row[1] == 'cd':
            if row[2] == '..':
                folders_visited.pop()
            elif row[2] == '/':
                folders_visited = ['root']
            else:
                folders_visited.append(row[2])
            row = read_strip_and_split(file)
        elif row[1] == 'ls':
            row = read_strip_and_split(file)
            while row[0] and row[0] != '$':
                if row[0] == 'dir':
                    G.add_edge(str(folders_visited), str(folders_visited+[row[1]]), weight=0)
                else:
                    G.add_edge(str(folders_visited), str(folders_visited+[row[1]]), weight=int(row[0]))
                row = read_strip_and_split(file)
    return G

def sum_of_small_folders(weight_list, threshold):
    sum = 0
    for folder_size in weight_list:
        if folder_size < threshold:
            sum += folder_size
    print("Combined weight is", sum)
    return 0

def define_recursive_edge_weights(G, node, weight_list):
    if len(G.adj[node]) > 0:
        sum_of_kids = 0
        count = 0
        for child_node in G.adj[node]:
            count+=1
            return_sum, weight_list = define_recursive_edge_weights(G, node=child_node, weight_list=weight_list)
            sum_of_kids += G[node][child_node]["weight"] + return_sum

        weight_list.append(sum_of_kids)
        return sum_of_kids, weight_list
    return 0, weight_list

def smallest_folder_to_delete(weight_list):
    outernmost_folder_size = weight_list[-1]
    for folder_size in weight_list:
        if 70000000 - outernmost_folder_size + folder_size >= 30000000:
            print("Smallest folder to delete is", folder_size)
            break
    return 0

def node_weights(G):
    sum_of_all, weight_list = define_recursive_edge_weights(G, node=str(['root']), weight_list=[])
    weight_list.sort()
    print("Weights are", weight_list)
    return  weight_list

def make_network(file_name):
    file = open(file_name, 'r')
    G = nx.DiGraph()
    return read_file_into_graph(G, file, folders_visited=['root'])

def draw_graph(G):
    nx.draw(G, node_size=3)
    plt.show()
    return 0

def main():
    G = make_network("day7-input.txt")
    print("The network is a", G)
    print("There are", len(nx.cycle_basis(G.to_undirected())), "loops in the network")

    weight_list = node_weights(G)
    smallest_folder_to_delete(weight_list)
    sum_of_small_folders(weight_list, threshold = 100000)
    return 0

main()