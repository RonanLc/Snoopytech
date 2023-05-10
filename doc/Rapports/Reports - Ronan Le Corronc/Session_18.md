# Week 13 - March 28, 2023 - 149h

During this session I focused on the kinematic study of the robot. As explained in [Report No. 14](https://github.com/RonanLc/Snoopytech/blob/main/doc/Rapports/Reports%20-%20Ronan%20Le%20Corronc/Session_14.md) we have to find the mathematical formulas allowing to pass from an orthonormal reference X Y Z to the angles of the leg.

I decided to start over because my previous calculations were underdeveloped and wrong.

## Schematics and name

For these calculations I used the following notations and diagrams:

![schematics](assets/session_18/schematics.png)

**Mx**, **My**, **Mz** correspond to the desired X, Y, Z displacement.

<br>

## Direct equations

So I was able to determine the following equations:

$$ AB^2 = A^2 + B^2 - 2 \times A \times B \times cos(\textcolor{green}{\Theta}) $$

$$ \textcolor{red}{Mx} \text{ = L } \times \text{cos(} \textcolor{green}{\Psi} \text{) + AB } \times \text{cos(} \textcolor{green}{\Phi} \text{ - arcsin(} \frac{A \times sin(\textcolor{green}{\Theta})}{AB} \text{))} \times \text{sin(} \textcolor{green}{\Psi} \text{)} $$

$$ \textcolor{red}{My} \text{ = L } \times \text{sin(} \textcolor{green}{- \Psi} \text{) + AB } \times \text{cos(} \textcolor{green}{\Phi} \text{ - arcsin(} \frac{A \times sin(\textcolor{green}{\Theta})}{AB} \text{))} \times \text{cos(} \textcolor{green}{\Psi} \text{)} $$

$$ \textcolor{red}{Mz} \text{ = AB } \times \text{sin(} \textcolor{green}{\Phi} \text{ - arcsin(} \frac{A \times sin(\textcolor{green}{\Theta})}{AB} \text{))} $$

These equations correspond to the direct equations, they allow to obtain the X, Y, Z positions by knowing the angles of the robot legs.

## Next

I will focus on the inverse equations, the ones that allow to find the angles of the leg by knowing the X, Y, Z positions.