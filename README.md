# Fract'ol - Computer Graphics Fractals

## Project Overview

**Fract'ol** is a computer graphics project focused on generating and exploring beautiful fractals. Using the MiniLibX graphical library, the project renders well-known fractals such as the Julia set and the Mandelbrot set, with interactive zoom and various graphical features. The project introduces concepts in complex numbers, fractal geometry, and event-driven graphical programming, providing hands-on experience with computer graphics.

The program allows users to visually explore fractals by zooming in and out and modifying parameters, offering a visually dynamic way to interact with these complex mathematical structures.

---

## Key Features

- **Program Name**: `fractol`
- **Fractals Supported**:
  - **Julia Set**: A famous fractal that can be customized by passing different parameters.
  - **Mandelbrot Set**: A well-known fractal that showcases the beauty of mathematical recursion.

- **Core Functionality**:
  - Interactive zoom using the mouse wheel, allowing near-infinite exploration of fractals.
  - Command-line arguments to select the fractal to display.
  - Dynamic coloring of the fractals to show depth, with the potential for psychedelic effects.

---

## Technical Details

- **Rendering**:
  - The program uses the **MiniLibX** library to open a window, handle mouse and keyboard events, and render images.
  - Fractals are displayed in real-time, with smooth interaction, such as minimizing, switching between windows, and quitting the program cleanly.

- **Fractal Generation**:
  - The **Julia set** is customizable by passing parameters via the command line.
  - The **Mandelbrot set** is rendered by default or when specified via a parameter.

- **User Interaction**:
  - **Zoom**: The user can zoom in and out using the mouse wheel, exploring the fractal at deeper levels.
  - **Window Management**: The program supports closing the window using the ESC key or by clicking the window’s close button, ensuring a clean exit.

---

## Bonus Features

In addition to the core functionality, the following bonus features were implemented:

- **Additional Fractals**: Added support for an extra type of fractal (beyond the Julia and Mandelbrot sets).
- **Advanced Zoom**: The zoom follows the mouse position for a more interactive exploration experience.
- **View Navigation**: The view can be moved using the arrow keys, adding further control to explore different parts of the fractal.
- **Color Shifting**: The color range dynamically shifts, providing a visually appealing effect as the fractal is explored.

---

## Skills Demonstrated

- **Graphics Programming**: Developed proficiency with the MiniLibX library for opening windows, rendering images, and handling user events.
- **Complex Numbers and Fractals**: Gained understanding of fractal geometry and how to represent complex mathematical concepts visually.
- **Event-Driven Programming**: Implemented smooth handling of user inputs, such as mouse and keyboard events, to interact with the fractal.
- **Optimization in Graphics**: Applied optimization techniques to ensure the fractal rendering and zooming are responsive and efficient.

---

## Conclusion

The **Fract'ol** project provided an excellent introduction to computer graphics and the mathematical beauty of fractals. By rendering the Julia and Mandelbrot sets interactively, I gained valuable experience in graphical programming, event handling, and mathematical visualization. The dynamic exploration of fractals through zoom and real-time interaction was particularly rewarding, allowing for deep visual exploration of these stunning mathematical structures.
