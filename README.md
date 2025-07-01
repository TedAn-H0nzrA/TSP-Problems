# 🧭 Travelling Salesman Problem Simulator

An interactive application to visualize and solve the Travelling Salesman Problem (TSP) using the brute-force algorithm.

---

## 📌 Description

This application provides a visual simulation of the Travelling Salesman Problem. The user can place cities on the screen and observe the brute-force algorithm compute the optimal route to visit all cities exactly once and return to the starting point.

---

## 🎯 Features

- **Interactive city placement**: Click to add cities on the screen.
- **Real-time visualization**: Watch the algorithm explore all possible routes.
- **Dynamic display of the best path found**.
- **Live statistics**:
  - Number of cities
  - Total number of permutations to explore
  - Best distance found
  - Number of paths evaluated
  - Search progress (in %)

---

## 🎮 Controls

| Key          | Action                                      |
|--------------|---------------------------------------------|
| `T`          | Toggle city placement mode                  |
| `B`          | Start the brute-force algorithm             |
| `A`          | Start the ACO algorithm                     |
| `Space`      | Reset the simulation                        |
| `M`          | Toggle background music                     |
| `Left Click` | Add a city (when placement mode is active)  |

---

## 🧠 Implemented Algorithm: **Brute Force**

The brute-force algorithm explores every possible permutation of the cities to find the shortest route. While this guarantees the **optimal solution**, the performance **degrades rapidly** as the number of cities increases.

> Time complexity: `(n-1)!` where `n` is the number of cities

## 🧠 Implemented Algorithm: **Ant Colony Optimization**

The ACO algorithm use the behavior of ant walking throught the cities to find the shortest route. While this will not guarantees the **optimal solution**, but the performance **is fast** compare to the Brute-Force alogorithm.

### Performance indication (color-coded)

- 🟢 **Green** (≤ 5 cities): Fast computation
- 🟡 **Yellow** (6–7 cities): Moderate computation
- 🟠 **Orange** (8–9 cities): Slow computation
- 🔴 **Red** (≥ 10 cities): Very slow, not recommended

---

## ✅ Usage tips

1. Press `T` to activate city placement mode.
2. Click on the screen to place your cities.
3. Press `B` to start the brute-force algorithm or `A` for ACO algorithm.
4. Watch the progress and path update in real time.
5. Press `Space` to reset and try again.

---

## 🧪 Technical Challenges

- **Factorial Explosion**: The brute-force approach becomes impractical beyond 10-12 cities.
- **Precision vs Speed**: The simulator prioritizes finding the exact optimal solution over execution speed.
- **Visualization Performance**: Rendering all paths in real-time while maintaining responsive UI.

---

## 🗂️ Project Structure

```bash
├── inc/
│   ├── AI/            # Algorithm implementations (e.g., ACO)
│   ├── core/          # Core simulation logic and management
│   ├── entity/        # Classes representing simulation entities (e.g., Town, Path)
│   └── utils/         # Helper functions, constants, and utility classes
├── src/
│   ├── AI/            # Source files for AI algorithms
│   ├── core/          # Source files for core logic
│   ├── entity/        # Source files for entity classes
│   └── utils/         # Source files for utility functions
├── assets/
│   ├── fonts/         # Font files used in the UI
│   └── music/         # Background music and sound effects
├── out/               # Directory for the compiled executable
├── build/             # CMake build output directory
├── CMakeLists.txt     # CMake configuration file
└── README.md          # Project overview and instructions

```

## 🛠️ Build & Run (with CMake)

### Requirements

- [SFML 2.5+](https://www.sfml-dev.org/)
- CMake ≥ 3.10
- C++ compiler compatible with C++17

### 📦 Build Steps

```bash
# Create a build directory
mkdir build
cd build

# Generate build files using CMake
cmake ..

# Compile the project
cmake --build .

# Run the generated executable 
cd ../out/
./TSP_Problems
```

**💡 If SFML is not found automatically, you may need to set CMAKE_PREFIX_PATH or update the CMakeLists.txt to manually specify your library path.**

## 🔮 Future Perspectives

Potential improvements for future releases:

- Implementation of additional algorithms (Nearest Neighbor, Genetic Algorithm)
- Support for loading/saving city configurations
- Performance optimizations for larger problem sets
- Custom rendering options (city colors, path styles)

---

## Background Music

Music track: A Beautiful Garden by Aventure
Source: https://freetouse.com/music
Free Background Music for Video

## 🎓 Developed by Andrianina – Computer Science – 2025
