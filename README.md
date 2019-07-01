# mandelbrot
My first project written in C.  This code generates the classic mandelbrot set utilizing the stb_image_write library 
written by Sean Barret.  Interact with this program on the command line by specifying arguments in the following order..

1. maxIterations: how many iterations before a point is considered to be "in the set."
2. xRange: range of x values that the window will span (how zoomed in the set will appear).
3. centerX: specify the x-coordinate that will correspond to the center of the window.
4. centerI: specify the coordinate on the imaginary plane that will correspond to the center of the window.

Examples:
a) 
maxIterations = 200,

xRange = default,

centerX = default,

centerI = default,

![mandelbrot](https://user-images.githubusercontent.com/36753018/60391514-cf047280-9aa4-11e9-9455-cf21840d4d6f.png)

b) 
maxIterations = 250,

xRange = 0.5,

centerX = -0.75

centerI = 0.25

![screenshot_3](https://user-images.githubusercontent.com/36753018/60469457-93d38200-9c11-11e9-86b2-0a2f72685359.png)

c) main.c also contains a function called mandelbrotCubed() that can be used instead of mandelbrotSquared() to create
   a variation of the original set.  
   
   maxIterations = 250
   
   xRange = 4
   
   centerX = 0
   
   centerI = default
   
   
![screenshot_4](https://user-images.githubusercontent.com/36753018/60470014-a9e24200-9c13-11e9-8f97-13e4a421ec4b.png)
