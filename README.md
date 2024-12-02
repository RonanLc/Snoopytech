![IMG-2881](https://github.com/RonanLc/Snoopytech/assets/95374519/984105c5-4482-4240-9c9a-9b0ac6045800)

# Snoopytech - Autonomous Robot Dog 🐕

## 🌟 Presentation

Snoopytech is an ambitious project for an autonomous quadruped robot, designed to explore complex environments by combining agility and embedded intelligence. The robot uses 3-degree-of-freedom legs, brushless motors and integrates a computational architecture based on Arduino and NVIDIA. Behave or he might bite ! 

## ⚙️ Key features

1. **Mechanical structure** : 

   - 3-axis legs with brushless motors for smooth, dynamic movement.
   - Robust, lightweight design for stability in a variety of environments.

2. **Electronic components** :

    - **Arduino**: Sensor management and basic motion coordination.
    - **NVIDIA Jetson**: Advanced processing for computer vision, data analysis and real-time decision-making.
    - [**Brushless ACK-5312CP motors**](https://fr.aliexpress.com/item/33027613653.html?spm=a2g0o.detail.1000014.1.17b2287ekaLzga&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.14452.226710.0&scm_id=1007.14452.226710.0&scm-url=1007.14452.226710.0&pvid=d425404d-4615-440e-bf21-b715ba417a18&_t=gps-): Brushless motor for dog joint with reversible ESCs
    - [**RP LIDAR**](https://www.amazon.fr/Scanradius-LIDAR-Sensorscanner-Vermeidung-Hindernissen-Navigation/dp/B07VLFGT27/ref=asc_df_B07VLFGT27/?tag=googshopfr-21&linkCode=df0&hvadid=411439987151&hvpos=&hvnetw=g&hvrand=17858514273165735039&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdv): 360° LIDAR for environmental analysis
    - [**C505e HD Webcam**](https://www.amazon.fr/Logitech-Webcam-Micro-Longue-port%C3%A9e/dp/B08NZ52YYN/ref=sr_1_1?adgrpid=1363395356743550&hvadid=85212673713370&hvbmt=be&hvdev=c&hvlocphy=127159&hvnetw=o&hvqmt=e&hvtargid=kwd-85212758052269%3Aloc-66&hydadcr=15452_2293869&keywords=logitech+c505e&qid=1670692399&sr=8-1): HD camera for environmental analysis
    - [**MPU6050**](https://fr.aliexpress.com/item/32340949017.html?spm=a2g0o.productlist.0.0.587312adnNgBZj&algo_pvid=19376db7-79d4-41f3-91f8-c1871eddb2a7&algo_exp_id=19376db7-79d4-41f3-91f8-c1871eddb2a7-0&pdp_ext_f=%7B%22sku_id%22%3A%2210000000609322940%22%7D&pdp_npi=2%40d): IMU sensor with accelerometers and gyroscopes

3. **Software and algorithms** :

   - Motor control via specific controllers (ESC).
   - Implementation of kinematic models to ensure precise movement.
   - Integration of sensors for autonomous navigation.

## 🎯 Project objectives

- Develop a robot capable of walking, running and adapting to rough terrain.
- Incorporate artificial intelligence for tasks such as obstacle detection, object recognition and interaction with the environment.
- Test and validate locomotion and stability algorithms for quadruped robots.

## 🛠️ Project structure

The repository is organized as follows:

1. `Mechanical/` :
   - CAD design files and mechanical drawings.
   - Documentation on leg manufacturing and motor selection.

2. `Electronics/` :
   - Circuits for powering motors and interfacing with control boards.
   - ESC configuration for brushless motors.

3. `Software` :
   - Arduino code for low-level control of motors and sensors.
   - Python and C++ scripts for data processing and behavior management.
   - Simulation models to test algorithms before hardware integration.

4. `AI/` :
   - Computer vision models for real-time analysis (via Jetson).
   - Learning algorithms to optimize motion.

## 🚀 Progress and next steps

- **Current**: Tests of locomotion algorithms and motor calibration.
- **Upcoming** :
  - Full integration of sensors for autonomous navigation.
  - Development of a communication system for remote or collaborative control.
  - Energy optimization for extended autonomy.

## 📚 Documentation

- **Tutorials and Explanations**: Sample scripts are available in the `doc/` folder.

## 📫 Contact

If you have any questions or suggestions, please feel free to open an issue or contact me via [my GitHub](https://github.com/RonanLc).