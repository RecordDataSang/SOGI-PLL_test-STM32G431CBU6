# STM32 SOGI-PLL Project

## Overview / 项目简介

This project implements a **SOGI-PLL (Second-Order Generalized Integrator Phase-Locked Loop)** based on the STM32G431CBU6 microcontroller. It is designed to sample single-phase grid voltage and generate a synchronized sinusoidal reference signal with adjustable phase.

本项目基于 STM32G431CBU6 微控制器，实现了一种 **SOGI-PLL（广义二阶积分锁相环）**。系统用于采样单相交流电网电压，并生成同频、相位可调的参考正弦信号。

---

## Features / 项目内容

The repository includes:

* Hardware design (schematic & PCB)
* Simulink system-level simulation
* STM32CubeMX configuration file (.ioc)
* Core firmware source code

本项目包含以下内容：

* 原理图与 PCB 设计
* Simulink 系统级仿真模型
* 基于 STM32CubeMX 的配置文件（.ioc）
* 核心控制代码

---

## Usage / 使用方法

⚠️ This is **NOT a ready-to-run project**.

⚠️ 本项目**不是下载即可直接运行的完整工程**。

### Recommended Workflow / 推荐使用方式

1. Create your own STM32 project using STM32CubeMX
2. Configure peripherals according to the provided `.ioc` file
3. Generate code (MDK-ARM / Keil recommended)
4. Migrate the core source code from this repository
5. Adapt and debug according to your hardware platform

---

1. 使用 STM32CubeMX 创建工程
2. 参考本项目 `.ioc` 文件进行外设配置
3. 生成代码（推荐使用 Keil / MDK-ARM）
4. 将本项目核心代码移植到你的工程中
5. 根据实际硬件平台进行调试与适配

---

## Tutorial / 视频教程

A detailed video tutorial is available:

项目配套视频教程：

https://www.bilibili.com/video/BV1ELSmBHE7z/

---

## Notice / 使用说明

This project is provided as a reference for **code logic and implementation ideas**, intended for learning and technical exploration.

本项目仅提供**代码逻辑与实现思路参考**，用于学习与技术交流。

* Users should complete system integration and engineering implementation independently

* Users must adapt the design based on their own hardware and application requirements

* 具体工程实现需用户自行分析与完善

* 请结合自身硬件平台进行适配

---

## Disclaimer / 免责声明

Due to differences in hardware platforms, development environments, and application scenarios, the author does not guarantee that the code will work out-of-the-box in all cases.

由于不同硬件平台、开发环境及应用场景存在差异，作者不保证该代码在所有环境下均可直接运行。

Users must perform sufficient validation and testing before practical deployment.

在实际应用前，请务必完成充分的验证与调试。

The author assumes no responsibility for any direct or indirect issues arising from the use of this project.

对于因使用本项目所产生的任何直接或间接问题，作者不承担责任。

---

## Additional Notes / 补充说明

* PCB files are designed using Altium Designer (AD22)

* Ensure toolchain and firmware versions are compatible

* Recommended for users with basic STM32 and control theory knowledge

* PCB 使用 AD22 设计

* 请确保开发环境版本匹配

* 建议具备 STM32 与控制算法基础后使用

---

## License / 许可说明

This project is intended for educational use. For commercial usage, please ensure compliance with applicable regulations.

本项目用于学习交流，如需用于商业用途，请自行确保合规性。
