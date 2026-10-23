Unreal Engine C++ Virtual Production & VFX Framework
A lightweight, high-performance C++ framework designed for Unreal Engine, tailored for virtual production, LED volumes, In-Camera VFX (ICVFX), and commercial broadcasting.

🚀 Features
Real-Time Camera Tracking: Base actor template ready to integrate with external hardware tracking systems (e.g., Mo-Sys, Vive Mars) via custom SDK calls.

Dynamic Studio Lighting Control: Programmatic control over scene lighting and DMX protocol simulation hooks for real-time stage adjustments.

High-Performance VFX Blueprint Library: Native C++ math functions exposed to Blueprints to handle heavy data calculations (such as wave offsets or particle transformations) without frame drops.

📂 Project Structure
This framework consists of two main files:

UnifiedProductionActor.h (Header file declaring classes, components, and Blueprint functions)

UnifiedProductionActor.cpp (Source file containing the logic for tick updates, tracking simulations, and lighting)

⚙️ Installation & Setup
Open your Unreal Engine project (C++ project).

Create a new C++ class or add these files (UnifiedProductionActor.h and UnifiedProductionActor.cpp) into your project's Source/YourProjectName/ directory.

Compile your project from Visual Studio, Rider, or Xcode.

Drag and drop the AUnifiedProductionActor into your level viewport.
