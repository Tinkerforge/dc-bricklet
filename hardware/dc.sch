EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "DC V2 Bricklet"
Date "2020-01-09"
Rev "2.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2020, T.Schneidermann <tim@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L tinkerforge:CON-SENSOR2 P1
U 1 1 5B5B0B02
P 750 1600
F 0 "P1" H 600 2000 60  0000 C CNN
F 1 "CON-SENSOR2" V 900 1600 60  0000 C CNN
F 2 "kicad-libraries:CON-SENSOR2_180" H 850 1450 60  0001 C CNN
F 3 "" H 850 1450 60  0000 C CNN
	1    750  1600
	-1   0    0    -1  
$EndComp
$Comp
L tinkerforge:R_PACK4 RP1
U 1 1 5B5B1A4C
P 1950 1550
F 0 "RP1" H 1950 2000 50  0000 C CNN
F 1 "82" H 1950 1500 50  0000 C CNN
F 2 "tinkerforge:4X0402" H 1950 1550 50  0001 C CNN
F 3 "" H 1950 1550 50  0000 C CNN
	1    1950 1550
	1    0    0    1   
$EndComp
Text GLabel 2700 1600 2    47   Output ~ 0
S-CS
Text GLabel 2700 1700 2    47   Output ~ 0
S-CLK
Text GLabel 2700 1800 2    47   Output ~ 0
S-MOSI
Text GLabel 2700 1900 2    47   Input ~ 0
S-MISO
$Comp
L tinkerforge:C C1
U 1 1 5B5B1CC1
P 1450 2100
F 0 "C1" H 1500 2200 50  0000 L CNN
F 1 "220pF" H 1500 2000 50  0000 L CNN
F 2 "C0402E" H 1450 2100 60  0001 C CNN
F 3 "" H 1450 2100 60  0000 C CNN
	1    1450 2100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR01
U 1 1 5B5B1D24
P 1450 2350
F 0 "#PWR01" H 1450 2350 30  0001 C CNN
F 1 "GND" H 1450 2280 30  0001 C CNN
F 2 "" H 1450 2350 60  0000 C CNN
F 3 "" H 1450 2350 60  0000 C CNN
	1    1450 2350
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR02
U 1 1 5B5B1D64
P 750 2350
F 0 "#PWR02" H 750 2350 30  0001 C CNN
F 1 "GND" H 750 2280 30  0001 C CNN
F 2 "" H 750 2350 60  0000 C CNN
F 3 "" H 750 2350 60  0000 C CNN
	1    750  2350
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:+5V #PWR03
U 1 1 5B5B1DC0
P 1250 750
F 0 "#PWR03" H 1250 600 50  0001 C CNN
F 1 "+5V" H 1250 890 50  0000 C CNN
F 2 "" H 1250 750 50  0000 C CNN
F 3 "" H 1250 750 50  0000 C CNN
	1    1250 750 
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C2
U 1 1 5B5B1DF2
P 1800 1100
F 0 "C2" H 1850 1200 50  0000 L CNN
F 1 "10uF" H 1850 1000 50  0000 L CNN
F 2 "kicad-libraries:C0805E" H 1800 1100 60  0001 C CNN
F 3 "" H 1800 1100 60  0000 C CNN
	1    1800 1100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C3
U 1 1 5B5B1E37
P 2200 1100
F 0 "C3" H 2250 1200 50  0000 L CNN
F 1 "1uF" H 2250 1000 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 2200 1100 60  0001 C CNN
F 3 "" H 2200 1100 60  0000 C CNN
	1    2200 1100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:+3.3VP #PWR04
U 1 1 5B5B1FD2
P 2200 700
F 0 "#PWR04" H 2200 800 40  0001 C CNN
F 1 "+3.3VP" H 2200 825 40  0000 C CNN
F 2 "" H 2200 700 60  0000 C CNN
F 3 "" H 2200 700 60  0000 C CNN
	1    2200 700 
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR05
U 1 1 5B5B2027
P 2250 1450
F 0 "#PWR05" H 2250 1450 30  0001 C CNN
F 1 "GND" H 2250 1380 30  0001 C CNN
F 2 "" H 2250 1450 60  0000 C CNN
F 3 "" H 2250 1450 60  0000 C CNN
	1    2250 1450
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 1 1 5B5B218B
P 3950 7000
F 0 "U1" H 3950 7450 60  0000 C CNN
F 1 "XMC1???" H 3950 6550 60  0000 C CNN
F 2 "QFN24-4x4mm-0.5mm" H 4100 7750 60  0001 C CNN
F 3 "" H 4100 7750 60  0000 C CNN
	1    3950 7000
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 2 1 5B5B2270
P 3950 3550
F 0 "U1" H 3950 4150 60  0000 C CNN
F 1 "XMC1???" H 3950 2950 60  0000 C CNN
F 2 "QFN24-4x4mm-0.5mm" H 4100 4300 60  0001 C CNN
F 3 "" H 4100 4300 60  0000 C CNN
	2    3950 3550
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 3 1 5B5B22BE
P 3950 4650
F 0 "U1" H 3950 4950 60  0000 C CNN
F 1 "XMC1???" H 3950 4350 60  0000 C CNN
F 2 "QFN24-4x4mm-0.5mm" H 4100 5400 60  0001 C CNN
F 3 "" H 4100 5400 60  0000 C CNN
	3    3950 4650
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:XMC1XXX24 U1
U 4 1 5B5B2343
P 3950 5750
F 0 "U1" H 3950 6250 60  0000 C CNN
F 1 "XMC1???" H 3950 5250 60  0000 C CNN
F 2 "QFN24-4x4mm-0.5mm" H 4100 6500 60  0001 C CNN
F 3 "" H 4100 6500 60  0000 C CNN
	4    3950 5750
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR011
U 1 1 5B62D981
P 3400 7450
F 0 "#PWR011" H 3400 7200 50  0001 C CNN
F 1 "GND" H 3400 7300 50  0000 C CNN
F 2 "" H 3400 7450 50  0000 C CNN
F 3 "" H 3400 7450 50  0000 C CNN
	1    3400 7450
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:+3.3VP #PWR012
U 1 1 5B62D9DC
P 3400 6550
F 0 "#PWR012" H 3400 6650 40  0001 C CNN
F 1 "+3.3VP" H 3400 6675 40  0000 C CNN
F 2 "" H 3400 6550 60  0000 C CNN
F 3 "" H 3400 6550 60  0000 C CNN
	1    3400 6550
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:C C4
U 1 1 5B62DA0C
P 3400 6950
F 0 "C4" H 3425 7050 50  0000 L CNN
F 1 "100nF" H 3425 6850 50  0000 L CNN
F 2 "C0603F" H 3438 6800 50  0001 C CNN
F 3 "" H 3400 6950 50  0000 C CNN
	1    3400 6950
	1    0    0    -1  
$EndComp
Text GLabel 3300 5400 0    39   Output ~ 0
S-MISO
$Comp
L tinkerforge:LED D1
U 1 1 5B62E369
P 2000 3200
F 0 "D1" H 2000 3300 50  0000 C CNN
F 1 "BLUE" H 2000 3100 50  0000 C CNN
F 2 "D0603F" H 2000 3200 50  0001 C CNN
F 3 "" H 2000 3200 50  0000 C CNN
	1    2000 3200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:CONN_01X02 P3
U 1 1 5B62E89C
P 1350 3800
F 0 "P3" H 1350 3950 50  0000 C CNN
F 1 "BOOT" V 1450 3800 50  0000 C CNN
F 2 "SolderJumper" H 1350 3800 50  0001 C CNN
F 3 "" H 1350 3800 50  0000 C CNN
	1    1350 3800
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:GND #PWR014
U 1 1 5B62E929
P 1600 4050
F 0 "#PWR014" H 1600 3800 50  0001 C CNN
F 1 "GND" H 1600 3900 50  0000 C CNN
F 2 "" H 1600 4050 50  0000 C CNN
F 3 "" H 1600 4050 50  0000 C CNN
	1    1600 4050
	1    0    0    -1  
$EndComp
Text GLabel 3250 3800 0    39   Input ~ 0
S-CS
Text GLabel 3250 3900 0    39   Input ~ 0
S-CLK
Text GLabel 3250 4000 0    39   Input ~ 0
S-MOSI
Wire Wire Line
	2150 1600 2700 1600
Wire Wire Line
	2150 1700 2700 1700
Wire Wire Line
	2150 1900 2700 1900
Wire Wire Line
	2150 1800 2700 1800
Connection ~ 1450 1900
Wire Wire Line
	750  2050 750  2350
Wire Wire Line
	1250 750  1250 1300
Wire Wire Line
	1250 1300 1100 1300
Connection ~ 1800 1400
Wire Wire Line
	1100 1600 1750 1600
Wire Wire Line
	1750 1700 1100 1700
Wire Wire Line
	1100 1800 1750 1800
Wire Wire Line
	1100 1900 1450 1900
Wire Wire Line
	1100 1500 1600 1500
Wire Wire Line
	1600 1500 1600 800 
Wire Wire Line
	1600 800  1800 800 
Connection ~ 1800 800 
Wire Wire Line
	2250 1400 2250 1450
Connection ~ 2200 1400
Connection ~ 2200 800 
Wire Wire Line
	3400 7200 3600 7200
Connection ~ 3400 7200
Wire Wire Line
	3400 7300 3600 7300
Connection ~ 3400 7300
Wire Wire Line
	3400 6700 3600 6700
Connection ~ 3400 6700
Wire Wire Line
	1800 3200 1450 3200
Wire Wire Line
	1550 3850 1600 3850
Wire Wire Line
	1600 3850 1600 4050
Wire Wire Line
	3250 3800 3600 3800
Wire Wire Line
	3600 3900 3250 3900
Wire Wire Line
	3250 4000 3600 4000
Text Notes 1750 2450 0    47   ~ 0
SPI Slave/CH0\nP0.13 : USIC0_CH0-DX2F : SEL\nP0.14 : USIC0_CH0-DX1A : CLK\nP0.15 : USIC0_CH0-DX0B : MOSI\nP2.0 : USIC0_CH0-DOUT0 : MISO
Text Notes 550  7750 0    40   ~ 0
Copyright Tinkerforge GmbH 2020.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
$Comp
L tinkerforge:CONN_01X01 P2
U 1 1 5B62EAFF
P 1350 3550
F 0 "P2" H 1350 3650 50  0000 C CNN
F 1 "DEBUG" V 1450 3550 50  0000 C CNN
F 2 "DEBUG_PAD" H 1350 3550 50  0001 C CNN
F 3 "" H 1350 3550 50  0000 C CNN
	1    1350 3550
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:DRILL U5
U 1 1 5B633E5A
P 11050 6400
F 0 "U5" H 11100 6450 60  0001 C CNN
F 1 "DRILL" H 11050 6400 60  0000 C CNN
F 2 "DRILL_NP" H 11050 6400 60  0001 C CNN
F 3 "" H 11050 6400 60  0000 C CNN
	1    11050 6400
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U3
U 1 1 5B633F4A
P 10750 6400
F 0 "U3" H 10800 6450 60  0001 C CNN
F 1 "DRILL" H 10750 6400 60  0000 C CNN
F 2 "DRILL_NP" H 10750 6400 60  0001 C CNN
F 3 "" H 10750 6400 60  0000 C CNN
	1    10750 6400
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U4
U 1 1 5B633F8A
P 11050 6200
F 0 "U4" H 11100 6250 60  0001 C CNN
F 1 "DRILL" H 11050 6200 60  0000 C CNN
F 2 "DRILL_NP" H 11050 6200 60  0001 C CNN
F 3 "" H 11050 6200 60  0000 C CNN
	1    11050 6200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:DRILL U2
U 1 1 5B633FCA
P 10750 6200
F 0 "U2" H 10800 6250 60  0001 C CNN
F 1 "DRILL" H 10750 6200 60  0000 C CNN
F 2 "DRILL_NP" H 10750 6200 60  0001 C CNN
F 3 "" H 10750 6200 60  0000 C CNN
	1    10750 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 800  1800 900 
Wire Wire Line
	2200 700  2200 800 
Wire Wire Line
	1800 1300 1800 1400
Wire Wire Line
	2200 1400 2200 1300
Wire Wire Line
	3400 7150 3400 7200
Wire Wire Line
	3400 6550 3400 6700
Wire Wire Line
	1450 2350 1450 2300
Wire Wire Line
	1450 1900 1750 1900
Wire Wire Line
	1800 800  2200 800 
Wire Wire Line
	2200 1400 2250 1400
Wire Wire Line
	2200 800  2200 900 
Wire Wire Line
	3400 7200 3400 7300
Wire Wire Line
	3400 7300 3400 7450
Wire Wire Line
	3400 6700 3400 6750
$Comp
L tinkerforge:CONN_4 P5
U 1 1 5E22A9D5
P 10050 2850
F 0 "P5" H 10178 2891 50  0000 L CNN
F 1 "GPIO" H 10178 2800 50  0000 L CNN
F 2 "kicad-libraries:OQ_4P_Vertical" H 10050 2850 60  0001 C CNN
F 3 "" H 10050 2850 60  0000 C CNN
	1    10050 2850
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R16
U 1 1 5E372A4E
P 9600 2700
F 0 "R16" V 9550 2700 31  0000 C CNN
F 1 "2,2k" V 9600 2700 31  0000 C CNN
F 2 "kicad-libraries:R0805E" V 9494 2700 60  0001 C CNN
F 3 "" H 9600 2700 60  0000 C CNN
	1    9600 2700
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:Rs R17
U 1 1 5E373CBA
P 9600 2900
F 0 "R17" V 9550 2900 31  0000 C CNN
F 1 "2,2k" V 9600 2900 31  0000 C CNN
F 2 "kicad-libraries:R0805E" V 9494 2900 60  0001 C CNN
F 3 "" H 9600 2900 60  0000 C CNN
	1    9600 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	9450 2700 9500 2700
Wire Wire Line
	9450 2700 9450 2900
Wire Wire Line
	9450 2900 9500 2900
Text GLabel 9900 1300 2    50   Input ~ 0
V_GPIO
Connection ~ 9450 2700
$Comp
L tinkerforge:Rs R12
U 1 1 5E3D5D39
P 8500 2700
F 0 "R12" V 8450 2700 31  0000 C CNN
F 1 "1k" V 8500 2700 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 2700 60  0001 C CNN
F 3 "" H 8500 2700 60  0000 C CNN
	1    8500 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	9700 2800 9350 2800
$Comp
L tinkerforge:Rs R14
U 1 1 5E3FDDB8
P 9050 2800
F 0 "R14" V 9100 2750 31  0000 L CNN
F 1 "4,7k" V 9050 2750 31  0000 L CNN
F 2 "kicad-libraries:R0603F" H 9050 2800 60  0001 C CNN
F 3 "" H 9050 2800 60  0000 C CNN
	1    9050 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 2700 8850 2700
$Comp
L tinkerforge:Cs C11
U 1 1 5E3FE4CA
P 8850 2800
F 0 "C11" H 8700 2850 31  0000 L CNN
F 1 "100nF/100V" H 8700 2750 31  0000 L CNN
F 2 "kicad-libraries:C0603F" H 8850 2800 60  0001 C CNN
F 3 "" H 8850 2800 60  0000 C CNN
	1    8850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 2900 8850 2950
Wire Wire Line
	8850 2950 8950 2950
Wire Wire Line
	9050 2950 9050 2900
$Comp
L tinkerforge:GND #PWR0106
U 1 1 5E40F762
P 8950 2950
F 0 "#PWR0106" H 8950 2700 50  0001 C CNN
F 1 "GND" H 8800 2900 50  0000 C CNN
F 2 "" H 8950 2950 50  0000 C CNN
F 3 "" H 8950 2950 50  0000 C CNN
	1    8950 2950
	1    0    0    -1  
$EndComp
Connection ~ 8950 2950
Wire Wire Line
	8950 2950 9050 2950
$Comp
L tinkerforge:ZENER D6
U 1 1 5E410CF0
P 8150 3750
F 0 "D6" V 8050 3600 50  0000 L CNN
F 1 "Z3,3V" V 8200 3550 31  0000 L CNN
F 2 "kicad-libraries:MiniMelf" H 8150 3750 50  0001 C CNN
F 3 "" H 8150 3750 50  0000 C CNN
	1    8150 3750
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:GND #PWR0108
U 1 1 5E4209FD
P 8150 3950
F 0 "#PWR0108" H 8150 3700 50  0001 C CNN
F 1 "GND" H 8155 3777 50  0000 C CNN
F 2 "" H 8150 3950 50  0000 C CNN
F 3 "" H 8150 3950 50  0000 C CNN
	1    8150 3950
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Cs C9
U 1 1 5E421731
P 8300 3750
F 0 "C9" H 8350 3800 31  0000 L CNN
F 1 "100nF/100V" H 8350 3700 31  0000 L CNN
F 2 "kicad-libraries:C0603F" H 8300 3750 60  0001 C CNN
F 3 "" H 8300 3750 60  0000 C CNN
	1    8300 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3550 8300 3550
Wire Wire Line
	8300 3550 8300 3650
Wire Wire Line
	8300 3850 8300 3950
Wire Wire Line
	8300 3950 8150 3950
Connection ~ 8150 3950
Wire Wire Line
	8600 2700 8850 2700
Connection ~ 8850 2700
Wire Wire Line
	3600 3500 3100 3500
Text GLabel 3300 5500 0    39   Input ~ 0
GPIO0
Text GLabel 3300 5900 0    39   Input ~ 0
GPIO1
Wire Wire Line
	3300 5600 3600 5600
Wire Wire Line
	3600 5900 3300 5900
$Comp
L tinkerforge:Rs R1
U 1 1 5E7A08C6
P 2550 3200
F 0 "R1" V 2500 3200 31  0000 C CNN
F 1 "1k" V 2550 3200 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 2550 3200 60  0001 C CNN
F 3 "" H 2550 3200 60  0000 C CNN
	1    2550 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 3200 2450 3200
Wire Wire Line
	9700 3000 9350 3000
Connection ~ 8850 3100
Wire Wire Line
	8850 3100 8600 3100
Wire Wire Line
	8950 3350 9050 3350
Connection ~ 8950 3350
$Comp
L tinkerforge:GND #PWR0107
U 1 1 5E40FFD2
P 8950 3350
F 0 "#PWR0107" H 8950 3100 50  0001 C CNN
F 1 "GND" H 8800 3300 50  0000 C CNN
F 2 "" H 8950 3350 50  0000 C CNN
F 3 "" H 8950 3350 50  0000 C CNN
	1    8950 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3350 9050 3300
Wire Wire Line
	8850 3350 8950 3350
Wire Wire Line
	8850 3300 8850 3350
Wire Wire Line
	8850 3100 9050 3100
$Comp
L tinkerforge:Cs C12
U 1 1 5E40021F
P 8850 3200
F 0 "C12" H 8700 3250 31  0000 L CNN
F 1 "100nF/100V" H 8700 3150 31  0000 L CNN
F 2 "kicad-libraries:C0603F" H 8850 3200 60  0001 C CNN
F 3 "" H 8850 3200 60  0000 C CNN
	1    8850 3200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R15
U 1 1 5E3FCA96
P 9050 3200
F 0 "R15" V 9100 3150 31  0000 L CNN
F 1 "4,7k" V 9050 3150 31  0000 L CNN
F 2 "kicad-libraries:R0603F" H 9050 3200 60  0001 C CNN
F 3 "" H 9050 3200 60  0000 C CNN
	1    9050 3200
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R13
U 1 1 5E3D6C5E
P 8500 3100
F 0 "R13" V 8450 3100 31  0000 C CNN
F 1 "1k" V 8500 3100 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 3100 60  0001 C CNN
F 3 "" H 8500 3100 60  0000 C CNN
	1    8500 3100
	0    1    1    0   
$EndComp
Text GLabel 6200 3400 0    39   Output ~ 0
GPIO1
Wire Wire Line
	6400 3400 6200 3400
$Comp
L tinkerforge:GND #PWR0111
U 1 1 5E5484F9
P 6400 3600
F 0 "#PWR0111" H 6400 3350 50  0001 C CNN
F 1 "GND" H 6500 3500 39  0000 C CNN
F 2 "" H 6400 3600 50  0000 C CNN
F 3 "" H 6400 3600 50  0000 C CNN
	1    6400 3600
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R11
U 1 1 5E543CE8
P 6400 3500
F 0 "R11" V 6350 3500 31  0000 C CNN
F 1 "1k" V 6400 3500 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6400 3500 60  0001 C CNN
F 3 "" H 6400 3500 60  0000 C CNN
	1    6400 3500
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:+3.3VP #PWR0109
U 1 1 5E52F047
P 6500 2500
F 0 "#PWR0109" H 6500 2600 40  0001 C CNN
F 1 "+3.3VP" H 6500 2625 40  0000 C CNN
F 2 "" H 6500 2500 60  0000 C CNN
F 3 "" H 6500 2500 60  0000 C CNN
	1    6500 2500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:LTV-827 U7
U 1 1 5E3F5652
P 7300 3050
F 0 "U7" H 7275 3687 60  0000 C CNN
F 1 "LTV-827" H 7275 3581 60  0000 C CNN
F 2 "kicad-libraries:DIP_8_SMD" H 7300 2650 60  0001 C CNN
F 3 "" H 7300 2650 60  0000 C CNN
	1    7300 3050
	-1   0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R10
U 1 1 5E5444A9
P 6400 3100
F 0 "R10" V 6350 3100 31  0000 C CNN
F 1 "1k" V 6400 3100 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6400 3100 60  0001 C CNN
F 3 "" H 6400 3100 60  0000 C CNN
	1    6400 3100
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:GND #PWR0110
U 1 1 5E548087
P 6400 3200
F 0 "#PWR0110" H 6400 2950 50  0001 C CNN
F 1 "GND" H 6500 3100 39  0000 C CNN
F 2 "" H 6400 3200 50  0000 C CNN
F 3 "" H 6400 3200 50  0000 C CNN
	1    6400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3000 6400 3000
Text GLabel 6200 3000 0    39   Output ~ 0
GPIO0
Wire Wire Line
	7950 2700 8400 2700
Wire Wire Line
	7950 3000 8150 3000
Wire Wire Line
	7950 3400 8150 3400
Wire Wire Line
	8150 3400 8150 3000
Wire Wire Line
	7950 3100 8400 3100
Wire Wire Line
	6500 2500 6500 2700
Wire Wire Line
	6500 3100 6700 3100
Wire Wire Line
	6700 2700 6500 2700
Connection ~ 6500 2700
Wire Wire Line
	6500 2700 6500 3100
Connection ~ 6400 3000
Wire Wire Line
	6400 3000 6700 3000
Wire Wire Line
	6400 3400 6700 3400
Connection ~ 6400 3400
Wire Wire Line
	8150 3550 8150 3400
Connection ~ 8150 3550
Connection ~ 8150 3400
Wire Wire Line
	9050 2700 9350 2700
Wire Wire Line
	9350 2700 9350 2800
Connection ~ 9050 2700
Wire Wire Line
	9050 3100 9350 3100
Wire Wire Line
	9350 3100 9350 3000
Connection ~ 9050 3100
$Comp
L tinkerforge:LED D12
U 1 1 5E3CFAC3
P 2000 2900
F 0 "D12" H 2000 3000 50  0000 C CNN
F 1 "RED" H 2000 2800 50  0000 C CNN
F 2 "D0603F" H 2000 2900 50  0001 C CNN
F 3 "" H 2000 2900 50  0000 C CNN
	1    2000 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2900 2350 2900
Text Notes 1750 3000 0    31   ~ 0
Error
$Comp
L tinkerforge:LED D11
U 1 1 5E3F8FDF
P 2000 4500
F 0 "D11" H 2000 4600 50  0000 C CNN
F 1 "BLUE" H 2000 4400 50  0000 C CNN
F 2 "D0603F" H 2000 4500 50  0001 C CNN
F 3 "" H 2000 4500 50  0000 C CNN
	1    2000 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4500 2350 4500
Text Notes 1750 4600 0    31   ~ 0
CW
$Comp
L tinkerforge:LED D10
U 1 1 5E40B36E
P 2000 4800
F 0 "D10" H 2000 4900 50  0000 C CNN
F 1 "BLUE" H 2000 4700 50  0000 C CNN
F 2 "D0603F" H 2000 4800 50  0001 C CNN
F 3 "" H 2000 4800 50  0000 C CNN
	1    2000 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4800 2350 4800
Text Notes 1750 4900 0    31   ~ 0
CCW
$Comp
L tinkerforge:LED D9
U 1 1 5E47C76F
P 2000 5100
F 0 "D9" H 2000 5200 50  0000 C CNN
F 1 "BLUE" H 2000 5000 50  0000 C CNN
F 2 "D0603F" H 2000 5100 50  0001 C CNN
F 3 "" H 2000 5100 50  0000 C CNN
	1    2000 5100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R3
U 1 1 5E47C775
P 2550 5400
F 0 "R3" V 2500 5400 31  0000 C CNN
F 1 "1k" V 2550 5400 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 2550 5400 60  0001 C CNN
F 3 "" H 2550 5400 60  0000 C CNN
	1    2550 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 5100 2350 5100
Text Notes 1750 5300 0    31   ~ 0
GPIO0
$Comp
L tinkerforge:LED D8
U 1 1 5E48D22A
P 2000 5400
F 0 "D8" H 2000 5500 50  0000 C CNN
F 1 "BLUE" H 2000 5300 50  0000 C CNN
F 2 "D0603F" H 2000 5400 50  0001 C CNN
F 3 "" H 2000 5400 50  0000 C CNN
	1    2000 5400
	1    0    0    -1  
$EndComp
Text Notes 1750 5500 0    31   ~ 0
GPIO1
Wire Wire Line
	1550 3750 2450 3750
Wire Wire Line
	1450 2900 1800 2900
Wire Wire Line
	1450 4800 1800 4800
Wire Wire Line
	1450 4500 1800 4500
$Comp
L tinkerforge:+3.3VP #PWR08
U 1 1 5E5BF857
P 1450 4500
F 0 "#PWR08" H 1450 4600 40  0001 C CNN
F 1 "+3.3VP" H 1450 4625 40  0000 C CNN
F 2 "" H 1450 4500 60  0000 C CNN
F 3 "" H 1450 4500 60  0000 C CNN
	1    1450 4500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R_PACK_SINGLE RP5
U 1 1 5E60B317
P 2550 5100
F 0 "RP5" H 2550 5150 20  0000 C CNN
F 1 "1k" H 2550 5100 20  0000 C CNN
F 2 "kicad-libraries:0603X4" H 2550 5100 60  0001 C CNN
F 3 "" H 2550 5100 60  0000 C CNN
	1    2550 5100
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R_PACK_SINGLE RP5
U 2 1 5E60BAF8
P 2550 4800
F 0 "RP5" H 2550 4850 20  0000 C CNN
F 1 "1k" H 2550 4800 20  0000 C CNN
F 2 "kicad-libraries:0603X4" H 2550 4800 60  0001 C CNN
F 3 "" H 2550 4800 60  0000 C CNN
	2    2550 4800
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R_PACK_SINGLE RP5
U 3 1 5E60D0BA
P 2550 4500
F 0 "RP5" H 2550 4550 20  0000 C CNN
F 1 "1k" H 2550 4500 20  0000 C CNN
F 2 "kicad-libraries:0603X4" H 2550 4500 60  0001 C CNN
F 3 "" H 2550 4500 60  0000 C CNN
	3    2550 4500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:R_PACK_SINGLE RP5
U 4 1 5E60E2C9
P 2550 2900
F 0 "RP5" H 2550 2950 20  0000 C CNN
F 1 "1k" H 2550 2900 20  0000 C CNN
F 2 "kicad-libraries:0603X4" H 2550 2900 60  0001 C CNN
F 3 "" H 2550 2900 60  0000 C CNN
	4    2550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5400 2450 5400
Wire Wire Line
	2750 5100 3200 5100
Wire Wire Line
	1550 3550 2450 3550
Wire Wire Line
	2650 3200 3600 3200
$Comp
L tinkerforge:+3.3VP #PWR0113
U 1 1 5E9A2D7D
P 1450 2800
F 0 "#PWR0113" H 1450 2900 40  0001 C CNN
F 1 "+3.3VP" H 1450 2925 40  0000 C CNN
F 2 "" H 1450 2800 60  0000 C CNN
F 3 "" H 1450 2800 60  0000 C CNN
	1    1450 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3300 3600 3300
Wire Wire Line
	3100 3400 3600 3400
Wire Wire Line
	2750 2900 3200 2900
Wire Wire Line
	3200 2900 3200 3100
Wire Wire Line
	3200 3100 3600 3100
Wire Wire Line
	1450 4500 1450 4800
Connection ~ 1450 4800
Wire Wire Line
	1450 4800 1450 5100
Wire Wire Line
	2750 4500 3600 4500
Wire Wire Line
	3600 4600 3000 4600
Wire Wire Line
	3000 4600 3000 4800
Wire Wire Line
	3000 4800 2750 4800
Wire Wire Line
	1450 5100 1800 5100
Wire Wire Line
	3200 5100 3200 4700
Wire Wire Line
	3200 4700 3600 4700
Wire Wire Line
	1450 2800 1450 2900
Connection ~ 1450 2900
Wire Wire Line
	1450 2900 1450 3200
Wire Wire Line
	1100 1400 1800 1400
Wire Wire Line
	1800 1400 2200 1400
$Sheet
S 5850 6950 800  700 
U 5EAFEC80
F0 "DRV" 50
F1 "DRV.sch" 50
$EndSheet
Wire Wire Line
	9450 1300 9900 1300
Wire Wire Line
	9450 1300 9450 2700
$Comp
L tinkerforge:Rs R5
U 1 1 5E9148F8
P 8900 1600
F 0 "R5" V 8950 1550 31  0000 L CNN
F 1 "100k" V 8850 1550 31  0000 L CNN
F 2 "kicad-libraries:R0603F" H 8900 1600 60  0001 C CNN
F 3 "" H 8900 1600 60  0000 C CNN
	1    8900 1600
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:Rs R6
U 1 1 5E914E32
P 8900 1950
F 0 "R6" V 8950 1900 31  0000 L CNN
F 1 "10k" V 8850 1900 31  0000 L CNN
F 2 "kicad-libraries:R0603F" H 8900 1950 60  0001 C CNN
F 3 "" H 8900 1950 60  0000 C CNN
	1    8900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 1700 8900 1800
Wire Wire Line
	8900 1500 8900 1300
Wire Wire Line
	8900 1300 9450 1300
Connection ~ 9450 1300
Wire Wire Line
	8900 2050 8900 2200
$Comp
L tinkerforge:GND #PWR09
U 1 1 5E9246E4
P 8900 2200
F 0 "#PWR09" H 8900 1950 50  0001 C CNN
F 1 "GND" H 8750 2150 50  0000 C CNN
F 2 "" H 8900 2200 50  0000 C CNN
F 3 "" H 8900 2200 50  0000 C CNN
	1    8900 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 1800 8450 1800
Connection ~ 8900 1800
Wire Wire Line
	8900 1800 8900 1850
Text GLabel 8450 1800 0    50   Output ~ 0
VIN
Text GLabel 3300 5800 0    39   Input ~ 0
VIN
Wire Wire Line
	3600 5800 3300 5800
Text GLabel 3100 3500 0    39   Output ~ 0
IN1
Text GLabel 3100 3400 0    39   Output ~ 0
IN2
Text GLabel 3100 3300 0    39   Output ~ 0
nSLEEP
Text GLabel 3300 5600 0    39   Input ~ 0
nFAULT
Text GLabel 3300 5700 0    39   Input ~ 0
SNSOUT
Text GLabel 2100 6000 0    50   Input ~ 0
SO
Wire Wire Line
	2450 3550 2450 3600
Wire Wire Line
	2450 3600 3600 3600
Wire Wire Line
	2450 3700 2450 3750
Wire Wire Line
	2450 3700 3600 3700
Wire Wire Line
	3300 5700 3600 5700
Wire Wire Line
	3600 5500 3300 5500
$Comp
L tinkerforge:Rs R2
U 1 1 5E9B3691
P 2500 6000
F 0 "R2" V 2450 6000 31  0000 C CNN
F 1 "7,5k" V 2500 6000 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 2500 6000 60  0001 C CNN
F 3 "" H 2500 6000 60  0000 C CNN
	1    2500 6000
	0    1    1    0   
$EndComp
$Comp
L tinkerforge:Rs R4
U 1 1 5E9B4017
P 2700 6150
F 0 "R4" V 2650 6150 31  0000 C CNN
F 1 "10k" V 2700 6150 31  0000 C CNN
F 2 "kicad-libraries:R0603F" H 2700 6150 60  0001 C CNN
F 3 "" H 2700 6150 60  0000 C CNN
	1    2700 6150
	-1   0    0    1   
$EndComp
$Comp
L tinkerforge:GND #PWR06
U 1 1 5E9B43D7
P 2700 6250
F 0 "#PWR06" H 2700 6000 50  0001 C CNN
F 1 "GND" H 2700 6100 50  0000 C CNN
F 2 "" H 2700 6250 50  0000 C CNN
F 3 "" H 2700 6250 50  0000 C CNN
	1    2700 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 6000 2700 6050
Wire Wire Line
	2400 6000 2100 6000
Wire Wire Line
	2600 6000 2700 6000
Connection ~ 2700 6000
Wire Wire Line
	3300 5400 3600 5400
Wire Wire Line
	2650 5400 2900 5400
Wire Wire Line
	2900 5400 2900 5250
Wire Wire Line
	2900 5250 3450 5250
Wire Wire Line
	3450 5250 3450 4800
Wire Wire Line
	3450 4800 3600 4800
Wire Wire Line
	1450 5400 1450 5100
Wire Wire Line
	1450 5400 1800 5400
Connection ~ 1450 5100
Connection ~ 1450 4500
Wire Wire Line
	2700 6000 3600 6000
NoConn ~ 3600 6100
$EndSCHEMATC
