import random
import time

# Room index to name mapping
room_name = {0: 'A', 1: 'B'}

# Set random starting room
def set_vacuum_location():
    return random.randint(0, 1)

# Generate random dirty/clean state for rooms
def generate_random_dirty_state():
    return [random.choice([True, False]), random.choice([True, False])]

# Clean a room
def clean_room(room_index, env_state):
    print(f"Cleaning Room {room_name[room_index]}...")
    env_state[room_index] = False
    time.sleep(1)
    return env_state

# Simple Reflex Agent Logic
def simple_reflex_agent():
    vacuum_location = set_vacuum_location()
    env_state = generate_random_dirty_state()
    cleaned_room_count = 0

    print("Initial State:")
    print(f"Room A: {'Dirty' if env_state[0] else 'Clean'}")
    print(f"Room B: {'Dirty' if env_state[1] else 'Clean'}\n")

    while cleaned_room_count < 2:
        print(f"Vacuum is in Room {room_name[vacuum_location]}")
        print(f"Current State: A: {'Dirty' if env_state[0] else 'Clean'}, B: {'Dirty' if env_state[1] else 'Clean'}")

        if env_state[vacuum_location]:
            env_state = clean_room(vacuum_location, env_state)
        else:
            print(f"Room {room_name[vacuum_location]} is already clean.")
            time.sleep(1)

        cleaned_room_count += 1

        if cleaned_room_count < 2:
            vacuum_location = 1 - vacuum_location
            print("Moving to the other room...\n")
            time.sleep(1.5)

    print("\nAll rooms are clean. Task completed.")

# Main Function
def main():
    print("Welcome to the Vacuum Cleaner Program\n")
    simple_reflex_agent()

# Run the program
if __name__ == "__main__":
    main()
