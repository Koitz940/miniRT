*This project has been created as part of the 42 curriculum by gcassi-d, xwu.*

# miniRT
![BALLS](<Screenshot from 2026-03-15 13-55-40.png>)

## Description

**miniRT** is a minimal ray tracer developed as part of the 42 School curriculum. The goal of the project is to build a simple **ray tracing engine** capable of rendering 3D scenes using basic geometric primitives and lighting calculations.

Ray tracing is a rendering technique that simulates the way light interacts with objects. Rays are cast from a virtual camera into a scene, and intersections with objects are calculated to determine the color of each pixel.

The program reads a **.rt scene file** that describes the scene configuration, including:

* Camera
* Ambient light
* Light sources
* Objects (spheres, planes, cylinders)

Using this information, the engine computes how rays interact with the scene and generates a rendered image displayed in a window.

This project focuses on understanding fundamental concepts of **computer graphics**, including:

* Ray–object intersections
* Vector mathematics
* Lighting models
* Transformations
* Camera space

## Features

* Ray tracing renderer
* Scene parsing from `.rt` files
* Support for:

  * Spheres
  * Planes
  * Cylinders
* Ambient and point lighting
* Basic shading
* Object transformations
* Interactive controls for camera, lights, and objects

## Instructions

### Requirements

* **C compiler** (gcc or clang)
* **Make**
* **MiniLibX**
* **macOS or Linux**

### Compilation

Clone the repository and compile the project using:

```bash
git clone <repository_url>
cd miniRT
make
```

This will produce the executable:

```
miniRT
```

### Execution

Run the program with a scene file:

```bash
./miniRT scenes/example.rt
```

A rendering window will open displaying the generated image.

### Key Bindings

```
[ESC]              close program
[BackSpace]        deselect figure
[l or L]           select light

[p or P] + object  move object (absolute)
[m] + object       move object (relative)
[M] + object       move object (relative to camera)

[r] + object       rotate object (absolute)
[R] + object       rotate object (relative to camera)

[f] + object       resize object
[+] + object       resize (+) object
[-] + object       resize (-) object

Camera controls:
[m]                move camera (relative)
[p]                move camera (absolute)
[M]                move camera (relative to camera)
[r]                rotate camera (absolute)
[R]                rotate camera (relative to camera)
[+]                increase FOV (+) camera
[-]                decrease FOV (-) camera
```

## Scene File Format

Scenes are defined using a `.rt` file that contains the scene configuration.

Example:

```
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255

sp 0,0,20 20 255,0,0
pl 0,0,0 0,1,0 255,255,255
cy 50,0,20 0,0,1 14.2 21.42 10,0,255
```

Where:

* `A` → Ambient light
* `C` → Camera
* `L` → Light
* `sp` → Sphere
* `pl` → Plane
* `cy` → Cylinder

## Technical Concepts

The implementation relies on several core concepts from computer graphics:

* **Ray casting**
* **Ray-object intersection algorithms**
* **Vector algebra**
* **Phong/Basic lighting models**
* **Camera projection**

Each pixel is computed by casting a ray from the camera into the scene and calculating the closest intersection with objects.

## Resources

The following resources were useful for understanding ray tracing and computer graphics concepts:

* *Ray Tracing in One Weekend* – Peter Shirley
* Scratchapixel – https://www.scratchapixel.com
* LearnOpenGL – https://learnopengl.com
* 42 MiniLibX documentation
* Wikipedia articles on ray tracing and vector mathematics

### AI Usage

AI was used **only to assist in writing this README file**.
No AI tools were used for the design, implementation, debugging, or development of the ray tracer itself.
