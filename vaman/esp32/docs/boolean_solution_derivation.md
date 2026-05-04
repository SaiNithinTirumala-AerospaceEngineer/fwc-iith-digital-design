# ESP32 GATE Question — Boolean Solution Derivation

**Author:** Tirumala Sai Nithin | FWC22187 | IIT Hyderabad

## Problem

A Boolean function F of three variables X, Y, and Z is given as
F (X, Y, Z) = (Xʹ + Y + Z)˖(X + Yʹ + Zʹ )˖(Xʹ + Y + Zʹ )˖( Xʹ Yʹ Zʹ + Xʹ Y Zʹ + X Y Zʹ )
Which one of the following is true?
1. F (X, Y, Z) = (X + Y + Zʹ)˖( Xʹ + Yʹ +Zʹ
2. F (X, Y, Z) = (Xʹ + Y)˖(X + Y ʹ+ Zʹ )
3. F (X, Y, Z) = Xʹ Zʹ + Y Zʹ
4. F (X, Y, Z) = Xʹ Yʹ Z + X Y Z
Solution:
F (X, Y, Z) = (Xʹ + Y + Z)˖(X + Yʹ + Zʹ )˖(Xʹ + Y + Zʹ )˖( Xʹ Yʹ Zʹ + Xʹ Y Zʹ + X Y Zʹ )
Now we will try to minimise one by one;
⇒ F (X, Y, Z) = (Xʹ + Y + Z)˖(X + Yʹ + Zʹ )˖(Xʹ + Y + Zʹ ).(X'Z' + XYZ')
⇒ F (X, Y, Z) = (Xʹ + Y + Z)˖(X + Yʹ + Zʹ )˖(Xʹ + Y + Zʹ )(X' + Y) Z'
Apply Distributive law:
⇒ (X' + Y) (X + Y' + Z') (X' Y' + X' Y + X Y) Z'
⇒ (X' + Y) (X + Y' + Z').(X' + X Y)Z'
⇒ (X, + Y) (X + Y' + Z') (X' + Y) Z' )
⇒ (X' + Y) (X + Y' + Z') Z'
⇒ (X' + Y) (X Z' + Y' Z' + Z')
⇒ (X' + Y) (X + Y' + 1) Z'
⇒ (X + Y) Z'
F = X' Z' + Y Z'