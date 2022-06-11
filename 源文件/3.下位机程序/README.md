# 下位机程序

以下是各文件夹的版本与作用：

- servo：仅调试伺服电机位置。后因对齐问题遂放弃使用伺服电机的方案。

- stepper_serial：步进电机**串行**执行旋转操作的版本。

- test_stepper_direction：仅调试步进电机的旋转方向。如果旋转方向不对，可以通过Micro-USB串口通讯更改每个电机的旋转方向，具体操作参考第一部分makerbase的说明书。

- stepper_parallel：步进电机**部分并行**执行旋转操作的**正式版本**，已烧录至Arduino下位机中。