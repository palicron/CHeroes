CHeroes: C++ Combat Simulator
CHeroes is a high-performance, turn-based combat simulation laboratory developed in C++20. This project serves as a technical showcase for advanced software architecture, memory management, and design patterns, specifically focusing on the core mechanics that drive game engines without relying on external frameworks.

🚀 Project Overview
The simulation generates a roster of procedural heroes with randomized classes, attributes, and skill sets. The player selects a champion to face a "Gauntlet" of remaining heroes in a strategic turn-based battle. The project is designed to be a "Zero-Leak" environment, utilizing modern C++ paradigms to handle complex object lifecycles.

🛠️ Technical Focus (Core Competencies)
This laboratory was built to demonstrate proficiency in:

Modern Memory Management: Strict adherence to RAII principles using Smart Pointers (std::unique_ptr, std::shared_ptr). No manual new/delete calls are used, ensuring a memory-safe application.

Advanced OOP & Polymorphism: * Abstract base classes with pure virtual functions.

Virtual destructors for safe cleanup of inherited classes.

Design Patterns:

Factory Pattern: Decoupling object creation for heroes and procedural ability generation.

State Pattern: Managing combat flow (Input, Execution, Resolution) to avoid monolithic conditional logic.

STL & Modern Headers: * Efficient use of std::vector and std::unordered_map.

Robust randomness using the <random> header (std::mt19937) instead of legacy C functions.

C++20 Standard: Leveraging modern initializers and language features for cleaner, safer code.

🎮 Game Loop
Generation: The engine populates a pool of heroes (Vanguard, Striker, Sage) with randomized stats.

Selection: The player claims ownership of a hero; remaining heroes are queued as enemies.

Battle: Turn-based logic where speed, health, and class-specific abilities interact.

Persistence: The loop continues as long as the player desires, with a complete memory reset between sessions.

💻 Setup
Compiler: ISO C++20 Standard (Tested on MSVC / Visual Studio 2022).

Platform: Console Application (CLI).
