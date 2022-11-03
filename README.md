# Procesamiento de Imágenes por Computador 
#### Master Universitario en Robótica y Automatización - UC3M

Computer Vision basics!

## Setup

First install opencv. This repo works with Ubuntu 22.04 LTS and OpenCV 4.5, anyway it should be easy to move to another version.

``` sudo apt install libopencv-dev```

Then, clone this repository.

``` git clone https://github.com/cristinaluna/pic_practices```

Once cloned, go to the repo directory and type

``` mkdir build ```

This creates a directory called build. Go to that directory

``` cd build ```

Now we need to compile the files. At this moment the CMakeLists compiles only one file, maybe you have to change the __practica__ you want to compile. Remember that this is a work in progress

``` cmake .. ```

And then...

``` make ```

Now you have an executable with the exercise you compiled. 

Enjoy!

## TODO

- [] Modify CMakeLists in order to compile all files directly
- [] Add Python code
