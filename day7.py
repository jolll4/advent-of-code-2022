import networkx as nx
import matplotlib.pyplot as plt

def read_and_strip(file):
    return file.readline().rstrip()

def folder_size(G, row, file, folders_visited):
    while row:
        if 'cd' in row:
            if '..' in row:
                folders_visited.pop()
            elif '/' not in row:
                line = row.rsplit(' ')
                folders_visited.append(line[2])
            row = read_and_strip(file)
        elif 'ls' in row:
            row = read_and_strip(file)
            while row and row[0] != '$':
                line = row.rsplit(' ')
                if line[0] == 'dir':
                    G.add_edge(folders_visited[-1], line[1], weight=0)
                else:
                    G.add_edge(folders_visited[-1], line[1], weight=int(line[0]))
                row = read_and_strip(file)
    return G

def make_network(file):
    G = nx.DiGraph()
    row = read_and_strip(file)
    return folder_size(G, row, file, folders_visited=['root'])

def main():
    file = open("day7-input.txt", 'r')
    G = make_network(file)
    print(G)
    nx.draw(G)
    plt.show()

main()