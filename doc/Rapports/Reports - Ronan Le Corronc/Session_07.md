# Week 49 - December 9, 2022 - 59h

## Gearbox sizing

I had several constraints to determine how I was going to make the gearbox.

The first one was the maximum size of the large pinion. I didn't want to go more than 50mm over the diameter (stator size of the motor) to not have too big parts in the shoulder.

I chose to use a 1.2 pitch for the gears. This means that here I would use an external pinion of 40 teeth:

$$ \text{40} \times \text{1.2 = 48mm} $$

And my second constraint was the size of the pinion connected to the motor. To be able to aim it on the rotor without worries, I needed a pinion of more than 18mm. So I chose to use a 20 teeth pinion.

$$ \text{20} \times \text{1.2 = 24mm} $$

An epicyclic gear is composed of 4 different parts. 

- The central pinion (Red) named ``P'' for the continuation
- The crown gear (Green) named ``C'' for the continuation
- The satellites (Yellow) named ``S`` for the continuation
- The satellite holder (Cyan)

In view of my constraints I decided to divide the gearbox in 3 parts. I will put in series 2 epicycloidal trains (R1 & R2) then a gearbox with a belt (R3).

<br>

After reading up on epicyclic gears, I discovered that there are several rules to follow when determining which pinion sizes to use.

- Reduction ratio for the fixed gear :

$$ \frac{Zp}{Zp + Zc} $$

- Number of teeth of the parts :

$$ \text{Zc = Zp + 2} \times \text{Zs} $$

- Number of satellites (Nbr):

$$ \frac{Zp}{Zs} \text{+ 1  = Nbr} $$

<br>

We can therefore determine the following equation :

$$ \text{R1 + R2 + R3 = Rtotal} $$

$$ \Leftrightarrow \frac{20}{20 + 40} \times \frac{x}{x + 40} \times \frac{12}{y} = \frac{1}{50} $$

<br>

Let's determine ``x`` :

$$ \text{Zc = Zp + 2} \times \text{Zs} $$

$$ \Leftrightarrow \frac{Zc - Zp}{2} \text{ = Zs} $$

$$ \Leftrightarrow \frac{Zp \times 2}{Zc - Zp} \text{+ 1 = Nbr} $$

$$ \Leftrightarrow \frac{Zc \times (Nbr -1)}{1 + Nbr} \text{ = Zp}$$

For the best stability I chose to put 3 satellites.

$$ \frac{40 \times (3 - 1)}{1 + 3} \text{ = 20}$$

This gearbox will therefore be sized like the first one.

$$ \frac{Zc - Zp}{2} \text{ = Zs} $$

$$ \frac{40 - 20}{2} \text{ = 10} $$

So we have all the sizes of the gears for the planetary gearing:

- Zc = 40 teeth
- Zp = 20 teeth
- Zs = 10 teeth

It remains now to determine the size of the pulley for the last gear (y):


$$ \frac{20}{20 + 40} \times \frac{20}{20 + 40} \times \frac{12}{y} = \frac{1}{50} $$

$$ \frac{20}{20 + 40} \times \frac{20}{20 + 40} \times 50 = \frac{y}{12} $$

$$ \frac{20}{20 + 40} \times \frac{20}{20 + 40} \times 50 \times 12 = y $$

$$ y \simeq 66 $$

The last calculation being an approximation because we cannot have a decimal number of teeth. The final reduction ratio will be :


$$ \Leftrightarrow \frac{20}{20 + 40} \times \frac{20}{20 + 40} \times \frac{12}{66} = \frac{1}{49.5} $$

But this will in no way prevent the gearbox from working properly.

<br>

## Gearbox modeling

The epicyclic gearbox is therefore composed of 13 parts shown below and 8 ball bearings.

![reduct parts](assets/session_7/reduct_part.png)

So I put it all together to get the following setup:

![reduct assembly](assets/session_7/reduct_assembly.png)

These parts will be printed with an SLA printer. I felt that the uncertainty of FDM printing would not be strong enough and would have too large an area of insertitude.

So I was able to assemble the leg to these reducers. The design is not finished yet and some details are still to be modified but we can already have an idea of the general shape of the final assembly of the leg.

![leg assembly](assets/session_7/leg_assembly.png)

<br>

## Gearbox printing

My big concern about this gearbox was the feasibility. The gears must be strong enough to support the torque and the speed. The bearings must have no backlash to minimize friction. And the gears must not have any play either or the system will fail.

Since we are going to use 3D printing I was very doubtful that it would really work.

So I decided to print a few parts so I could try and learn about SLA printing.

![3D printed part](assets/session_7/3D_printed_part.png)

The parts went on correctly. I had no problems with it and the accuracy of the parts surprised me. There doesn't seem to be any uncertainty like with FDM printing. I am finally very optimistic about the manufacturing of this system.

<br>

## Next week

So now I'm going to focus on building the system by running as much printing as possible and continuing to correct and modify the errors I encounter on the 3D design.