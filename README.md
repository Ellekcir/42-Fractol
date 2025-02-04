
# What You Need to Know

### Complex Numbers
A Complex Number is a combination of a **Real Number** and an **Imaginary Number**.

### Real Numbers
Real Numbers are numbers that you commonly encounter in everyday life, and they include values such as:

- 1  
- 12.38  
- −0.8625  
- 3/4  
- √2  
- 1998  

In fact, nearly any number you can think of is a Real Number!

### Imaginary Numbers
Imaginary Numbers are special because when squared, they give a negative result. Normally, this doesn't happen with real numbers, because:

- When we square a positive number, we get a positive result.
- When we square a negative number, we also get a positive result (since a negative times a negative equals a positive).

For example:  
- -2 x -2 = +4

However, we **imagine** that such numbers exist, because they serve a specific purpose in mathematics and other fields.

The "unit" imaginary number (like 1 for Real Numbers) is i, which is the square root of −1

- i = √(-1)
When we square i we get −1

- i^2 = −1

The letter z is often used for a complex number:

- z = a + bi

z is a Complex Number
a and b are Real Numbers
i is the unit imaginary number = √−1
we refer to the real part and imaginary part using Re and Im like this:

- Re(z) = a
- Im(z) = b

For more detailed information on complex numbers, refer to this [link](https://www.mathsisfun.com/numbers/complex-numbers.html).

## Mandelbrot
The Mandelbrot Set is a mathematical set of points that are defined by a simple equation, but exhibit a rich and complex behavior. It is named after the mathematician Benoit Mandelbrot. 
The equation for the Mandelbrot set is given by:

$$
Z_{n+1} = Z_n^2 + C
$$

Where:
- \( Z_n \) is a complex number representing the current value in the sequence.
- \( C \) is a constant complex number, the point in the complex plane representing both real and imaginary value.
- \( Z_{n+1} \) is the next value in the sequence, calculated by squaring the current value \( Z_n \) and adding \( C \).

The Mandelbrot set consists of all points \( C \) in the complex plane for which the sequence does not diverge when iterated from \( Z_0 = 0 \).

It is based on a complex number equation 
$$
Z_{n+1} = Z_n^2 + C
$$ 
which is repeated until it:

 - diverges to infinity, where a color is chosen based on how fast it diverges
 - does not diverge, and forms the actual Mandelbrot Set, shown as black.

## Steps to Visualize the Mandelbrot Set

### 1. **Coordinate System**
The complex plane is a 2D grid:
- The **x-axis** represents the **real** part of the complex number \( C \).
- The **y-axis** represents the **imaginary** part of \( C \).

Each point on this grid corresponds to a unique value of \( C \).

### 2. **Iteration**
For each point \( C \) in the grid, we calculate the sequence of values using the equation \( Z_{n+1} = Z_n^2 + C \), starting from \( Z_0 = 0 \). This iteration is repeated for a maximum number of steps.

- If the value of \( Z_n \) remains bounded (does not go to infinity), the point \( C \) is considered to be in the Mandelbrot set.
- If \( Z_n \) diverges (i.e., the value becomes infinitely large), the point is outside the Mandelbrot set.

### 3. **Boundaries**
Points that belong to the Mandelbrot set do not diverge and remain bounded after many iterations. These points are typically visualized in **black** or a dark color.

### 4. **Coloring**
Points that do not belong to the Mandelbrot set are colored based on how quickly they diverge:
- **Bright colors** (e.g., red, blue, green) indicate how fast a point diverges, with colors changing as the points move further away from the set.
- The faster the divergence, the brighter or more intense the color.

### 5. **Shape and Details**
The boundary of the Mandelbrot set is intricate and fractal-like. It roughly resembles a "heart" or "seahorse" shape. The closer you zoom into the boundary, the more complex and detailed the fractal pattern becomes.

# Julia Set

The **Julia Set** is a fractal  equation is recursive, meaning each new value depends on the previous one defined by the iterative equation:

$$
Z_{n+1} = Z_n^2 + C
$$


Where:
- \( Z_n \) is a complex number.
- \( C \) is a constant complex number that determines the shape of the fractal.
- \( Z_{n+1} \) is the next value in the sequence.

## Iteration Process:

1. Start with an initial value \( Z_0 \) (usually \( 0 \) or a point in the complex plane).
2. Compute \( Z_1 \), then \( Z_2 \), then \( Z_3 \), and so on.
3. If the sequence **remains bounded**, the point belongs to the Julia Set.
4. If the sequence **diverges** (tends to infinity), the point does **not** belong to the set.

## Visualization:

- The **x-axis** represents the real part of \( Z \).
- The **y-axis** represents the imaginary part of \( Z \).
- **Bounded points** are colored black.
- **Diverging points** are colored based on how quickly they escape.

By varying \( C \), different Julia Set patterns emerge, creating intricate and self-similar fractal structures.


# Burning Ship Fractal

The **Burning Ship Fractal** is generated using the equation:

$$
Z_{n+1} = (|\text{Re}(Z_n)| + i|\text{Im}(Z_n)|)^2 + C
$$

Where:
- \( Z_n \) starts at 0.
- \( C \) is the complex coordinate of each point.
- The absolute values of the real and imaginary parts are taken before squaring.

### Visualization:
- The **x-axis** represents the real part of \( C \).
- The **y-axis** represents the imaginary part of \( C \).
- The fractal forms a "ship-like" structure with chaotic details.
- Points that remain bounded are black, while escaped points are colored based on their iteration count.

---

## Conclusion
- The **Julia Set** depends on a fixed complex number \( C \) and produces different shapes based on \( C \).
- The **Burning Ship Fractal** has a distinctive, chaotic structure created by taking absolute values before squaring.

Both fractals demonstrate the beauty of mathematical iteration in the complex plane.


## Understanding mlx_hook

The **MiniLibX (MLX) mlx_hook** function is used to bind event handlers to specific events in your program. The function format is:

- mlx_hook(window, event, mask, function, param);
- window → The target window.
- event → The event type (key press, mouse movement, etc.).
- mask → A bitmask defining which events are listened for.
- function → The callback function that handles the event.
- param → A pointer (typically to a struct) that holds relevant data.

Common MLX Event Codes & Masks
Below is a list of commonly used event types and their masks:

Event Name	Code	Mask	Description
KeyPress	2	1L << 0	Key pressed
KeyRelease	3	1L << 1	Key released
ButtonPress	4	1L << 2	Mouse button pressed
ButtonRelease	5	1L << 3	Mouse button released
MotionNotify	6	1L << 6	Mouse moved
EnterNotify	7	1L << 4	Mouse enters window
LeaveNotify	8	1L << 5	Mouse leaves window
FocusIn	9	1L << 9	Window gains focus
FocusOut	10	1L << 10	Window loses focus
Expose	12	1L << 15	Window exposed (redraw)
DestroyNotify	17	0	Window close (X button)

What are Events?
An event is something that happens while the program is running.
Some common examples:

Pressing a key (like ESC or spacebar) 🖥️⌨️
Moving the mouse 🖱️
Clicking a mouse button 🖱️🔘
Closing the window ❌

In coding, we call these "events", and mlx_hook is used to listen for them.

How Does mlx_hook Work?
The mlx_hook function has the following format:


mlx_hook(window, event, mask, function, param);
Part	What it does
window	The window where the event happens.
event	The type of event (e.g., key press, mouse move, etc.).
mask	A filter that tells MiniLibX which events to listen for.
function	The function that runs when the event happens.
param	Extra information you can pass (not always needed).


Event	Code	Mask	What it Does
KeyPress	2	1L << 0	When a key is pressed.
KeyRelease	3	1L << 1	When a key is released.
ButtonPress	4	1L << 2	When a mouse button is clicked.
ButtonRelease	5	1L << 3	When a mouse button is released.
MotionNotify	6	1L << 6	When the mouse moves.
DestroyNotify	17	0	When the window is closed.

What does 1L mean?
1 is just the number 1 in binary (0001).
L stands for long (a long integer).
<< X means "shift the bits left by X places."
Example: 1L << 3
1L in binary:

0000 0000 0000 0000 0000 0000 0000 0001
If we shift it left by 3, it becomes:

0000 0000 0000 0000 0000 0000 0000 1000
This equals 8 in decimal.

So when you see 1L << X, it means "set the X-th bit to 1", which helps tell MiniLibX which events to listen for.