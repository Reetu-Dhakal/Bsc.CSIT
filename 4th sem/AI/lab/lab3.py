from collections import deque

# Adjacency list of the Graph
adj_list = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# Status codes:
# 1 = Ready (Unvisited)
# 2 = Waiting (In Queue)
# 3 = Visited
def initialize_status(graph):
    return {node: 1 for node in graph}

# BFS Search Algorithm
def bfs_search(start, dest, graph):
    queue = deque([start])
    status = initialize_status(graph)
    status[start] = 2
    path = []

    while queue:
        current = queue.popleft()
        path.append(current)
        status[current] = 3

        if current == dest:
            break

        for neighbor in graph[current]:
            if status[neighbor] == 1:
                queue.append(neighbor)
                status[neighbor] = 2

    return path

# Function to display adjacency list
def display_adjacency_list(graph):
    print("Adjacency List:")
    for node, neighbors in graph.items():
        print(f"{node} -> {neighbors}")

# Main function
def main():
    display_adjacency_list(adj_list)
    start = input("Enter Start Node: ").upper()
    dest = input("Enter Destination Node: ").upper()

    if start not in adj_list or dest not in adj_list:
        print("Invalid start or destination node.")
        return

    path = bfs_search(start, dest, adj_list)
    print(f"\nTraversal from {start} to {dest}:")
    print(" → ".join(path), "→ End")

if __name__ == "__main__":
    main()
