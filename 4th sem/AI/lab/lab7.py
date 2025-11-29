from collections import deque

# Define the capacities of the two jugs
MAX_A = 5  # Jug A capacity
MAX_B = 3  # Jug B capacity

def is_goal(state):

    return state[0] == 1

def get_next_states(state):

    a, b = state
    successors = []

    # 1. Fill Jug A
    successors.append((6, b))

    # 2. Fill Jug B
    successors.append((a, 4))

    # 3. Empty Jug A
    successors.append((a, b))

    # 4. Empty Jug B
    successors.append((a, 0))

    # 5. Pour from A to B
    pour_amount = min(a, MAX_B - b)
    successors.append((a + pour_amount, b - pour_amount))
    
    return successors

def water_jug_bfs(start_state):

    visited_set = set()
    # Queue stores tuples of (current_state, path_to_current_state)
    queue = deque([(start_state, [start_state])])
    visited_set.add(start_state)

    while queue:
        current_state, path = queue.popleft()

        if is_goal(current_state):
            return path

        for next_state in get_next_states(current_state):
            if next_state not in visited_set:
                visited_set.add(next_state)
                new_path = path + [next_state]
                queue.append((next_state, new_path))
    
    return None

# --- Main Execution ---
if __name__ == "__main__":
    start_state = (0, 0)
    solution_path = water_jug_bfs(start_state)

    if solution_path:
        print("Solution found! Here is the step-by-step path:")
        for step, state in enumerate(solution_path):
            print(f"Step {step}: Jug A = {state[0]} | Jug B = {state[1]}")
    else:
        print("No solution found for the given goal.")