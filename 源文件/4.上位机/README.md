# 上位机程序

## Prerequisites
- Ubuntu 18.04 (NOT windows)
- Python3.8
- Numpy
- Pyserial (NOT serial)
- OpenCV

## Usage

Before running program, you have to make sure **your computer is connected to your rubik's cube solver via USB** and the center block of your rubik's cube is **GREEN** on the **LEFT** side, **WHITE** on the **FRONT** side, **BLUE** on the **RIGHT** side, **YELLOW** on the **BACK** side, **ORANGE** on the **TOP** side, **RED** on the **BOTTOM** side.

1. Run `main.py`.

2. Click `Recognize` button.

    1. Solvable, just click the `Solve` button.

    2. Unsolvable, enter the position and color manually(eg. R1 and Red), and click **Correct** button. After correction, click `Verify` botton to check the correction.

        1. Solvable, click the `Solve` button.

        2. Unsolvable again, enter position and color manually again untill it's solvable.
