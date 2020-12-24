# Frequency_plot_arduino
plot the frequency of an input signal on a char LCD as a custom character sequence
UM666 ic is a Melody generator using PWMsignals to generate a melody stored in its rom .
The datasheet shows which part numbers have which melody ,but there are more melodies than is mentioned in its table.
Just like in old style computers that used to havea charcter rom. the arduino is using the character memory present in the LCD driver board to use a pseudo bitmap mode.
The bitmap is stored as a "font" in its character memory and used as needed giving its index.
the bitmap is just a sraight line for now , can update the binary matrix to use nay custom symbol

future extensions , find a way to use the whole screen and show a scrolling graph 
