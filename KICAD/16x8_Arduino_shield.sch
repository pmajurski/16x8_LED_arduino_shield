EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_LED:MAX7219 UMAX1
U 1 1 5ED6D575
P 9700 3750
F 0 "UMAX1" H 9700 4931 50  0000 C CNN
F 1 "MAX7219" H 9700 4840 50  0000 C CNN
F 2 "game_device_footprint_lib:MAX2719_custom" H 9650 3800 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX7219-MAX7221.pdf" H 9750 3600 50  0001 C CNN
	1    9700 3750
	1    0    0    -1  
$EndComp
$Comp
L Driver_LED:MAX7219 UMAX2
U 1 1 5ED6E047
P 9700 6500
F 0 "UMAX2" H 9700 7681 50  0000 C CNN
F 1 "MAX7219" H 9700 7590 50  0000 C CNN
F 2 "game_device_footprint_lib:MAX2719_custom" H 9650 6550 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX7219-MAX7221.pdf" H 9750 6350 50  0001 C CNN
	1    9700 6500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW108
U 1 1 5ED6F90D
P 6900 8350
F 0 "SW108" H 6900 8635 50  0000 C CNN
F 1 "SW_Push" H 6900 8544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6900 8550 50  0001 C CNN
F 3 "~" H 6900 8550 50  0001 C CNN
	1    6900 8350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW104
U 1 1 5ED70165
P 5000 6250
F 0 "SW104" H 5000 6535 50  0000 C CNN
F 1 "SW_SPDT" H 5000 6444 50  0000 C CNN
F 2 "game_device_footprint_lib:SPDT_switch_custom" H 5000 6250 50  0001 C CNN
F 3 "~" H 5000 6250 50  0001 C CNN
	1    5000 6250
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C201
U 1 1 5ED707FB
P 8400 7900
F 0 "C201" H 8578 7946 50  0000 L CNN
F 1 "10uF" H 8578 7855 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 8400 7900 50  0001 C CNN
F 3 "~" H 8400 7900 50  0001 C CNN
	1    8400 7900
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C202
U 1 1 5ED738CF
P 8950 7900
F 0 "C202" H 9128 7946 50  0000 L CNN
F 1 "100nF" H 9128 7855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8950 7900 50  0001 C CNN
F 3 "~" H 8950 7900 50  0001 C CNN
	1    8950 7900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 4550 10300 4550
Text Label 9100 7200 0    50   ~ 0
SCLK
Wire Wire Line
	9300 4450 8900 4450
Wire Wire Line
	9300 4350 8900 4350
Wire Wire Line
	9300 4550 8900 4550
Text Label 8900 4450 0    50   ~ 0
SCLK
Wire Wire Line
	9300 7100 9100 7100
Wire Wire Line
	9300 7200 9100 7200
Text Label 9100 7100 0    50   ~ 0
CS
Text Label 8900 4350 0    50   ~ 0
CS
Text Label 10150 4550 0    50   ~ 0
MAX1_OUT
Text Label 8900 7300 0    50   ~ 0
MAX1_OUT
Wire Wire Line
	8900 7300 9300 7300
Text Label 8900 4550 0    50   ~ 0
MOSI
Wire Wire Line
	9700 4750 9700 4900
$Comp
L Device:R R101
U 1 1 5ED7EE99
P 8550 2400
F 0 "R101" H 8620 2446 50  0000 L CNN
F 1 "50K" H 8620 2355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8480 2400 50  0001 C CNN
F 3 "~" H 8550 2400 50  0001 C CNN
	1    8550 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R202
U 1 1 5ED81A61
P 8700 5700
F 0 "R202" H 8770 5746 50  0000 L CNN
F 1 "50K" H 8770 5655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8630 5700 50  0001 C CNN
F 3 "~" H 8700 5700 50  0001 C CNN
	1    8700 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5700 9150 5700
Wire Wire Line
	8700 5550 8700 5500
Wire Wire Line
	8550 2250 8550 2150
Wire Wire Line
	9700 5500 8700 5500
Connection ~ 8700 5500
Wire Wire Line
	8700 5500 8700 5400
Wire Wire Line
	9700 2750 9250 2750
Wire Wire Line
	9250 2750 9250 2150
Wire Wire Line
	9250 2150 8550 2150
Wire Wire Line
	8400 8150 8750 8150
Wire Wire Line
	8400 7650 8550 7650
Wire Wire Line
	8550 7650 8550 7450
Connection ~ 8550 7650
Wire Wire Line
	8550 7650 8950 7650
Wire Wire Line
	8750 8150 8750 8350
Wire Wire Line
	8750 8350 9700 8350
Wire Wire Line
	9700 7500 9700 8350
Connection ~ 8750 8150
Wire Wire Line
	8750 8150 8950 8150
$Comp
L pspice:C C101
U 1 1 5ED9B0ED
P 8100 4000
F 0 "C101" H 8278 4046 50  0000 L CNN
F 1 "10uF" H 8278 3955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 8100 4000 50  0001 C CNN
F 3 "~" H 8100 4000 50  0001 C CNN
	1    8100 4000
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C102
U 1 1 5ED9B0F3
P 8650 4000
F 0 "C102" H 8828 4046 50  0000 L CNN
F 1 "100nF" H 8828 3955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8650 4000 50  0001 C CNN
F 3 "~" H 8650 4000 50  0001 C CNN
	1    8650 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4250 8450 4250
Wire Wire Line
	8100 3750 8250 3750
Wire Wire Line
	8250 3750 8250 3550
Connection ~ 8250 3750
Wire Wire Line
	8250 3750 8650 3750
Connection ~ 8450 4250
Wire Wire Line
	8450 4250 8650 4250
Wire Wire Line
	9700 4900 8450 4900
Wire Wire Line
	8450 4250 8450 4900
$Comp
L Switch:SW_Push SW105
U 1 1 5EDA223B
P 5700 8350
F 0 "SW105" H 5700 8635 50  0000 C CNN
F 1 "SW_Push" H 5700 8544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5700 8550 50  0001 C CNN
F 3 "~" H 5700 8550 50  0001 C CNN
	1    5700 8350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW106
U 1 1 5EDA3647
P 6300 7950
F 0 "SW106" H 6300 8235 50  0000 C CNN
F 1 "SW_Push" H 6300 8144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6300 8150 50  0001 C CNN
F 3 "~" H 6300 8150 50  0001 C CNN
	1    6300 7950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW107
U 1 1 5EDA613D
P 6300 8800
F 0 "SW107" H 6300 9085 50  0000 C CNN
F 1 "SW_Push" H 6300 8994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6300 9000 50  0001 C CNN
F 3 "~" H 6300 9000 50  0001 C CNN
	1    6300 8800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW103
U 1 1 5EDA7642
P 4900 7200
F 0 "SW103" H 4900 7485 50  0000 C CNN
F 1 "SW_Push" H 4900 7394 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4900 7400 50  0001 C CNN
F 3 "~" H 4900 7400 50  0001 C CNN
	1    4900 7200
	1    0    0    -1  
$EndComp
Text Label 6150 3500 0    50   ~ 0
up
Text Label 6150 3200 0    50   ~ 0
select
Text Label 6150 3600 0    50   ~ 0
down
Text Label 6150 3400 0    50   ~ 0
right
Text Label 6150 3300 0    50   ~ 0
left
Text Label 6500 7950 0    50   ~ 0
up
Text Label 5100 7200 0    50   ~ 0
select
Text Label 6500 8800 0    50   ~ 0
down
Text Label 7100 8350 0    50   ~ 0
right
Text Label 5900 8350 0    50   ~ 0
left
$Comp
L parts_lib:8x8_dot_matrix ULED1
U 1 1 5EE4BC24
P 12550 3100
F 0 "ULED1" H 13328 3146 50  0000 L CNN
F 1 "8x8_dot_matrix" H 13328 3055 50  0000 L CNN
F 2 "game_device_footprint_lib:LuckyLight_8x8_LED_matrix" H 12400 3050 50  0001 C CNN
F 3 "" H 12400 3050 50  0001 C CNN
	1    12550 3100
	1    0    0    -1  
$EndComp
$Comp
L parts_lib:8x8_dot_matrix ULED2
U 1 1 5EE4D6CB
P 12050 6200
F 0 "ULED2" H 12828 6246 50  0000 L CNN
F 1 "8x8_dot_matrix" H 12828 6155 50  0000 L CNN
F 2 "game_device_footprint_lib:LuckyLight_8x8_LED_matrix" H 11900 6150 50  0001 C CNN
F 3 "" H 11900 6150 50  0001 C CNN
	1    12050 6200
	1    0    0    -1  
$EndComp
Text Notes 10800 8450 0    50   ~ 0
segment pins are current source\ndigit pins are current sink\n\ndigit 0 top row\ndigit 7 bottom row\n\nsegment dp leftmost column\nsegment g rightmost column\n
Wire Wire Line
	10100 5700 10300 5700
Wire Wire Line
	10100 5800 10300 5800
Wire Wire Line
	10100 5900 10300 5900
Wire Wire Line
	10100 6000 10300 6000
Wire Wire Line
	10100 6100 10300 6100
Wire Wire Line
	10100 6200 10300 6200
Wire Wire Line
	10100 6300 10300 6300
Wire Wire Line
	10100 6400 10300 6400
Text Label 10200 6500 0    50   ~ 0
m2_row1
Text Label 10200 6600 0    50   ~ 0
m2_row2
Text Label 10200 6700 0    50   ~ 0
m2_row3
Text Label 10200 6800 0    50   ~ 0
m2_row4
Text Label 10200 6900 0    50   ~ 0
m2_row5
Text Label 10200 7000 0    50   ~ 0
m2_row6
Text Label 10200 7100 0    50   ~ 0
m2_row7
Text Label 10200 7200 0    50   ~ 0
m2_row8
Text Label 10200 6400 0    50   ~ 0
m2_col1
Text Label 10200 5700 0    50   ~ 0
m2_col2
Text Label 10200 5800 0    50   ~ 0
m2_col3
Text Label 10200 5900 0    50   ~ 0
m2_col4
Text Label 10200 6000 0    50   ~ 0
m2_col5
Text Label 10200 6100 0    50   ~ 0
m2_col6
Text Label 10200 6200 0    50   ~ 0
m2_col7
Text Label 10200 6300 0    50   ~ 0
m2_col8
Wire Wire Line
	10100 2950 10300 2950
Wire Wire Line
	10100 3050 10300 3050
Wire Wire Line
	10100 3150 10300 3150
Wire Wire Line
	10100 3250 10300 3250
Wire Wire Line
	10100 3350 10300 3350
Wire Wire Line
	10100 3450 10300 3450
Wire Wire Line
	10100 3550 10300 3550
Wire Wire Line
	10100 3650 10300 3650
Wire Wire Line
	10100 3750 10300 3750
Wire Wire Line
	10100 3850 10300 3850
Wire Wire Line
	10100 3950 10300 3950
Wire Wire Line
	10100 4050 10300 4050
Wire Wire Line
	10100 4150 10300 4150
Wire Wire Line
	10100 4250 10300 4250
Wire Wire Line
	10100 4350 10300 4350
Wire Wire Line
	10100 4450 10300 4450
Text Label 10250 3750 0    50   ~ 0
m1_row1
Text Label 10250 3850 0    50   ~ 0
m1_row2
Text Label 10250 3950 0    50   ~ 0
m1_row3
Text Label 10250 4050 0    50   ~ 0
m1_row4
Text Label 10250 4150 0    50   ~ 0
m1_row5
Text Label 10250 4250 0    50   ~ 0
m1_row6
Text Label 10250 4350 0    50   ~ 0
m1_row7
Text Label 10250 4450 0    50   ~ 0
m1_row8
Text Label 10250 3650 0    50   ~ 0
m1_col1
Text Label 10250 2950 0    50   ~ 0
m1_col2
Text Label 10250 3050 0    50   ~ 0
m1_col3
Text Label 10250 3150 0    50   ~ 0
m1_col4
Text Label 10250 3250 0    50   ~ 0
m1_col5
Text Label 10250 3350 0    50   ~ 0
m1_col6
Text Label 10250 3450 0    50   ~ 0
m1_col7
Text Label 10250 3550 0    50   ~ 0
m1_col8
Wire Wire Line
	10100 6500 10300 6500
Wire Wire Line
	10100 6600 10300 6600
Wire Wire Line
	10100 6700 10300 6700
Wire Wire Line
	10100 6800 10300 6800
Wire Wire Line
	10100 6900 10300 6900
Wire Wire Line
	10100 7000 10300 7000
Wire Wire Line
	10100 7100 10300 7100
Wire Wire Line
	10100 7200 10300 7200
Text Label 12500 5350 1    50   ~ 0
m2_row1
Text Label 12000 5350 1    50   ~ 0
m2_row2
Text Label 12500 7050 3    50   ~ 0
m2_row3
Text Label 12200 5350 1    50   ~ 0
m2_row4
Text Label 11800 7050 3    50   ~ 0
m2_row5
Text Label 12400 7050 3    50   ~ 0
m2_row6
Text Label 11900 7050 3    50   ~ 0
m2_row7
Text Label 12200 7050 3    50   ~ 0
m2_row8
Text Label 12100 5350 1    50   ~ 0
m2_col1
Text Label 12000 7050 3    50   ~ 0
m2_col2
Text Label 12100 7050 3    50   ~ 0
m2_col3
Text Label 12400 5350 1    50   ~ 0
m2_col4
Text Label 12300 7050 3    50   ~ 0
m2_col5
Text Label 12300 5350 1    50   ~ 0
m2_col6
Text Label 11900 5350 1    50   ~ 0
m2_col7
Text Label 11800 5350 1    50   ~ 0
m2_col8
Text Label 13000 2250 1    50   ~ 0
m1_row1
Text Label 12500 2250 1    50   ~ 0
m1_row2
Text Label 13000 3950 3    50   ~ 0
m1_row3
Text Label 12700 2250 1    50   ~ 0
m1_row4
Text Label 12300 3950 3    50   ~ 0
m1_row5
Text Label 12900 3950 3    50   ~ 0
m1_row6
Text Label 12400 3950 3    50   ~ 0
m1_row7
Text Label 12700 3950 3    50   ~ 0
m1_row8
Text Label 12600 2250 1    50   ~ 0
m1_col1
Text Label 12500 3950 3    50   ~ 0
m1_col2
Text Label 12600 3950 3    50   ~ 0
m1_col3
Text Label 12900 2250 1    50   ~ 0
m1_col4
Text Label 12800 3950 3    50   ~ 0
m1_col5
Text Label 12800 2250 1    50   ~ 0
m1_col6
Text Label 12400 2250 1    50   ~ 0
m1_col7
Text Label 12300 2250 1    50   ~ 0
m1_col8
NoConn ~ 10100 7300
Text Label 6150 3700 0    50   ~ 0
inc_bright
Text Label 6150 3800 0    50   ~ 0
dec_bright
Text Label 4000 8250 0    50   ~ 0
inc_bright
Text Label 4000 8750 0    50   ~ 0
dec_bright
$Comp
L Switch:SW_Push SW101
U 1 1 5EFD6FF5
P 3800 8250
F 0 "SW101" H 3800 8535 50  0000 C CNN
F 1 "SW_Push" H 3800 8444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 3800 8450 50  0001 C CNN
F 3 "~" H 3800 8450 50  0001 C CNN
	1    3800 8250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW102
U 1 1 5EFDA6E7
P 3800 8750
F 0 "SW102" H 3800 9035 50  0000 C CNN
F 1 "SW_Push" H 3800 8944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 3800 8950 50  0001 C CNN
F 3 "~" H 3800 8950 50  0001 C CNN
	1    3800 8750
	1    0    0    -1  
$EndComp
NoConn ~ 5200 6350
Wire Wire Line
	8550 2550 8550 2950
Wire Wire Line
	8550 2950 9300 2950
Wire Wire Line
	8700 5850 9150 5850
Wire Wire Line
	9150 5850 9150 5700
$Comp
L Connector:Barrel_Jack J101
U 1 1 5EEA766F
P 3700 6350
F 0 "J101" H 3757 6675 50  0000 C CNN
F 1 "Barrel_Jack" H 3757 6584 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 3750 6310 50  0001 C CNN
F 3 "~" H 3750 6310 50  0001 C CNN
	1    3700 6350
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5EEB1A8F
P 2500 3900
F 0 "#FLG0101" H 2500 3975 50  0001 C CNN
F 1 "PWR_FLAG" H 2500 4073 50  0000 C CNN
F 2 "" H 2500 3900 50  0001 C CNN
F 3 "~" H 2500 3900 50  0001 C CNN
	1    2500 3900
	-1   0    0    1   
$EndComp
Text Label 4500 6250 0    50   ~ 0
9V
Wire Wire Line
	4000 6250 4200 6250
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5EEFB79A
P 4200 6250
F 0 "#FLG0102" H 4200 6325 50  0001 C CNN
F 1 "PWR_FLAG" H 4200 6423 50  0000 C CNN
F 2 "" H 4200 6250 50  0001 C CNN
F 3 "~" H 4200 6250 50  0001 C CNN
	1    4200 6250
	1    0    0    -1  
$EndComp
Connection ~ 4200 6250
Wire Wire Line
	4200 6250 4650 6250
Text Label 2900 3900 0    50   ~ 0
GND
Text Notes 8750 3600 0    50   ~ 0
also grnd at 9\n
$Comp
L power:GND #PWR0101
U 1 1 5EF58F78
P 2900 3900
F 0 "#PWR0101" H 2900 3650 50  0001 C CNN
F 1 "GND" H 2905 3727 50  0000 C CNN
F 2 "" H 2900 3900 50  0001 C CNN
F 3 "" H 2900 3900 50  0001 C CNN
	1    2900 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0102
U 1 1 5EF5D106
P 4650 6250
F 0 "#PWR0102" H 4650 6100 50  0001 C CNN
F 1 "+9V" H 4665 6423 50  0000 C CNN
F 2 "" H 4650 6250 50  0001 C CNN
F 3 "" H 4650 6250 50  0001 C CNN
	1    4650 6250
	1    0    0    -1  
$EndComp
Connection ~ 4650 6250
Wire Wire Line
	4650 6250 4800 6250
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5EF5E021
P 2500 3500
F 0 "#FLG0103" H 2500 3575 50  0001 C CNN
F 1 "PWR_FLAG" H 2500 3673 50  0000 C CNN
F 2 "" H 2500 3500 50  0001 C CNN
F 3 "~" H 2500 3500 50  0001 C CNN
	1    2500 3500
	-1   0    0    1   
$EndComp
Text Label 3550 4900 2    50   ~ 0
GND
Text Label 6150 3900 0    50   ~ 0
CS
Text Label 6150 4000 0    50   ~ 0
MOSI
Text Label 6150 4200 0    50   ~ 0
SCLK
Text Label 3550 5200 2    50   ~ 0
VIN
Text Label 3550 4800 2    50   ~ 0
GND
Text Label 3550 4700 2    50   ~ 0
GND
Text Label 3550 5100 2    50   ~ 0
5V
Wire Wire Line
	2900 3500 2500 3500
Text Label 2900 3500 2    50   ~ 0
5V
Wire Wire Line
	2500 3900 2900 3900
$Comp
L power:+5V #PWR0103
U 1 1 5F1967D6
P 2900 3500
F 0 "#PWR0103" H 2900 3350 50  0001 C CNN
F 1 "+5V" H 2915 3673 50  0000 C CNN
F 2 "" H 2900 3500 50  0001 C CNN
F 3 "" H 2900 3500 50  0001 C CNN
	1    2900 3500
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5F197987
P 8550 2150
F 0 "#PWR0104" H 8550 2000 50  0001 C CNN
F 1 "+5V" H 8565 2323 50  0000 C CNN
F 2 "" H 8550 2150 50  0001 C CNN
F 3 "" H 8550 2150 50  0001 C CNN
	1    8550 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5F19CCE7
P 8250 3550
F 0 "#PWR0105" H 8250 3400 50  0001 C CNN
F 1 "+5V" H 8265 3723 50  0000 C CNN
F 2 "" H 8250 3550 50  0001 C CNN
F 3 "" H 8250 3550 50  0001 C CNN
	1    8250 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5F1A1FE5
P 8700 5400
F 0 "#PWR0106" H 8700 5250 50  0001 C CNN
F 1 "+5V" H 8715 5573 50  0000 C CNN
F 2 "" H 8700 5400 50  0001 C CNN
F 3 "" H 8700 5400 50  0001 C CNN
	1    8700 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5F1A736E
P 8550 7450
F 0 "#PWR0107" H 8550 7300 50  0001 C CNN
F 1 "+5V" H 8565 7623 50  0000 C CNN
F 2 "" H 8550 7450 50  0001 C CNN
F 3 "" H 8550 7450 50  0001 C CNN
	1    8550 7450
	1    0    0    -1  
$EndComp
Connection ~ 8550 2150
$Comp
L power:GND #PWR0108
U 1 1 5F1E6E56
P 8750 8350
F 0 "#PWR0108" H 8750 8100 50  0001 C CNN
F 1 "GND" H 8755 8177 50  0000 C CNN
F 2 "" H 8750 8350 50  0001 C CNN
F 3 "" H 8750 8350 50  0001 C CNN
	1    8750 8350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5F1EC292
P 8450 4900
F 0 "#PWR0109" H 8450 4650 50  0001 C CNN
F 1 "GND" H 8455 4727 50  0000 C CNN
F 2 "" H 8450 4900 50  0001 C CNN
F 3 "" H 8450 4900 50  0001 C CNN
	1    8450 4900
	1    0    0    -1  
$EndComp
Text Label 5400 6150 0    50   ~ 0
VIN
Wire Wire Line
	5200 6150 5400 6150
Wire Wire Line
	4000 6450 4200 6450
$Comp
L power:GND #PWR0117
U 1 1 5F26A3BA
P 4200 6450
F 0 "#PWR0117" H 4200 6200 50  0001 C CNN
F 1 "GND" H 4205 6277 50  0000 C CNN
F 2 "" H 4200 6450 50  0001 C CNN
F 3 "" H 4200 6450 50  0001 C CNN
	1    4200 6450
	1    0    0    -1  
$EndComp
NoConn ~ 6150 5200
NoConn ~ 6150 5100
NoConn ~ 3550 5000
NoConn ~ 3550 4400
NoConn ~ 3550 3800
NoConn ~ 3550 3900
NoConn ~ 3550 4000
NoConn ~ 3550 4100
NoConn ~ 3550 4200
NoConn ~ 3550 4300
NoConn ~ 3550 3100
NoConn ~ 3550 3200
NoConn ~ 3550 3400
NoConn ~ 3550 3500
NoConn ~ 6150 4400
NoConn ~ 6150 3100
NoConn ~ 6150 4900
NoConn ~ 6150 4800
NoConn ~ 6150 4700
NoConn ~ 6150 4600
NoConn ~ 6150 4500
NoConn ~ 6150 4100
$Comp
L arduino_shields:Arduino_Uno_Shield XA1
U 1 1 5EEAE110
P 4850 4150
F 0 "XA1" H 4850 5537 60  0000 C CNN
F 1 "Arduino_Uno_Shield" H 4850 5431 60  0000 C CNN
F 2 "" H 6650 7900 60  0001 C CNN
F 3 "https://store.arduino.cc/arduino-uno-rev3" H 6650 7900 60  0001 C CNN
	1    4850 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5EFD20EC
P 4700 7200
F 0 "#PWR0110" H 4700 6950 50  0001 C CNN
F 1 "GND" H 4705 7027 50  0000 C CNN
F 2 "" H 4700 7200 50  0001 C CNN
F 3 "" H 4700 7200 50  0001 C CNN
	1    4700 7200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5EFD451A
P 3600 8250
F 0 "#PWR0111" H 3600 8000 50  0001 C CNN
F 1 "GND" H 3605 8077 50  0000 C CNN
F 2 "" H 3600 8250 50  0001 C CNN
F 3 "" H 3600 8250 50  0001 C CNN
	1    3600 8250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5EFD66EA
P 3600 8750
F 0 "#PWR0112" H 3600 8500 50  0001 C CNN
F 1 "GND" H 3605 8577 50  0000 C CNN
F 2 "" H 3600 8750 50  0001 C CNN
F 3 "" H 3600 8750 50  0001 C CNN
	1    3600 8750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5EFD897D
P 5500 8350
F 0 "#PWR0113" H 5500 8100 50  0001 C CNN
F 1 "GND" H 5505 8177 50  0000 C CNN
F 2 "" H 5500 8350 50  0001 C CNN
F 3 "" H 5500 8350 50  0001 C CNN
	1    5500 8350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5EFDAB94
P 6100 7950
F 0 "#PWR0114" H 6100 7700 50  0001 C CNN
F 1 "GND" H 6105 7777 50  0000 C CNN
F 2 "" H 6100 7950 50  0001 C CNN
F 3 "" H 6100 7950 50  0001 C CNN
	1    6100 7950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5EFDCDDA
P 6700 8350
F 0 "#PWR0115" H 6700 8100 50  0001 C CNN
F 1 "GND" H 6705 8177 50  0000 C CNN
F 2 "" H 6700 8350 50  0001 C CNN
F 3 "" H 6700 8350 50  0001 C CNN
	1    6700 8350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5EFDF049
P 6100 8800
F 0 "#PWR0116" H 6100 8550 50  0001 C CNN
F 1 "GND" H 6105 8627 50  0000 C CNN
F 2 "" H 6100 8800 50  0001 C CNN
F 3 "" H 6100 8800 50  0001 C CNN
	1    6100 8800
	0    1    1    0   
$EndComp
Connection ~ 8450 4900
Connection ~ 8750 8350
$EndSCHEMATC
