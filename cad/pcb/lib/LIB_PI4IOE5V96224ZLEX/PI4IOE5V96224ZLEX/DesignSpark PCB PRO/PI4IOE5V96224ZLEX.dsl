SamacSys ECAD Model
1407125/896458/2.49/33/3/Integrated Circuit

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r65_20"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.2) (shapeHeight 0.65))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r505_205"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 2.05) (shapeHeight 5.05))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "QFN40P300X600X80-33N" (originalName "QFN40P300X600X80-33N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r65_20) (pt -1.55, 2) (rotation 90))
			(pad (padNum 2) (padStyleRef r65_20) (pt -1.55, 1.6) (rotation 90))
			(pad (padNum 3) (padStyleRef r65_20) (pt -1.55, 1.2) (rotation 90))
			(pad (padNum 4) (padStyleRef r65_20) (pt -1.55, 0.8) (rotation 90))
			(pad (padNum 5) (padStyleRef r65_20) (pt -1.55, 0.4) (rotation 90))
			(pad (padNum 6) (padStyleRef r65_20) (pt -1.55, 0) (rotation 90))
			(pad (padNum 7) (padStyleRef r65_20) (pt -1.55, -0.4) (rotation 90))
			(pad (padNum 8) (padStyleRef r65_20) (pt -1.55, -0.8) (rotation 90))
			(pad (padNum 9) (padStyleRef r65_20) (pt -1.55, -1.2) (rotation 90))
			(pad (padNum 10) (padStyleRef r65_20) (pt -1.55, -1.6) (rotation 90))
			(pad (padNum 11) (padStyleRef r65_20) (pt -1.55, -2) (rotation 90))
			(pad (padNum 12) (padStyleRef r65_20) (pt -0.8, -3.05) (rotation 0))
			(pad (padNum 13) (padStyleRef r65_20) (pt -0.4, -3.05) (rotation 0))
			(pad (padNum 14) (padStyleRef r65_20) (pt 0, -3.05) (rotation 0))
			(pad (padNum 15) (padStyleRef r65_20) (pt 0.4, -3.05) (rotation 0))
			(pad (padNum 16) (padStyleRef r65_20) (pt 0.8, -3.05) (rotation 0))
			(pad (padNum 17) (padStyleRef r65_20) (pt 1.55, -2) (rotation 90))
			(pad (padNum 18) (padStyleRef r65_20) (pt 1.55, -1.6) (rotation 90))
			(pad (padNum 19) (padStyleRef r65_20) (pt 1.55, -1.2) (rotation 90))
			(pad (padNum 20) (padStyleRef r65_20) (pt 1.55, -0.8) (rotation 90))
			(pad (padNum 21) (padStyleRef r65_20) (pt 1.55, -0.4) (rotation 90))
			(pad (padNum 22) (padStyleRef r65_20) (pt 1.55, 0) (rotation 90))
			(pad (padNum 23) (padStyleRef r65_20) (pt 1.55, 0.4) (rotation 90))
			(pad (padNum 24) (padStyleRef r65_20) (pt 1.55, 0.8) (rotation 90))
			(pad (padNum 25) (padStyleRef r65_20) (pt 1.55, 1.2) (rotation 90))
			(pad (padNum 26) (padStyleRef r65_20) (pt 1.55, 1.6) (rotation 90))
			(pad (padNum 27) (padStyleRef r65_20) (pt 1.55, 2) (rotation 90))
			(pad (padNum 28) (padStyleRef r65_20) (pt 0.8, 3.05) (rotation 0))
			(pad (padNum 29) (padStyleRef r65_20) (pt 0.4, 3.05) (rotation 0))
			(pad (padNum 30) (padStyleRef r65_20) (pt 0, 3.05) (rotation 0))
			(pad (padNum 31) (padStyleRef r65_20) (pt -0.4, 3.05) (rotation 0))
			(pad (padNum 32) (padStyleRef r65_20) (pt -0.8, 3.05) (rotation 0))
			(pad (padNum 33) (padStyleRef r505_205) (pt 0, 0) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -2.125 3.625) (pt 2.125 3.625) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 2.125 3.625) (pt 2.125 -3.625) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 2.125 -3.625) (pt -2.125 -3.625) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -2.125 -3.625) (pt -2.125 3.625) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.5 3) (pt 1.5 3) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.5 3) (pt 1.5 -3) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.5 -3) (pt -1.5 -3) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.5 -3) (pt -1.5 3) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.5 2.6) (pt -1.1 3) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -1.875, 2.6) (radius 0.1) (startAngle 0.0) (sweepAngle 0.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -1.875, 2.6) (radius 0.1) (startAngle 180.0) (sweepAngle 180.0) (width 0.2))
		)
	)
	(symbolDef "PI4IOE5V96224ZLEX" (originalName "PI4IOE5V96224ZLEX")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 4) (pt 0 mils -300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -325 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 5) (pt 0 mils -400 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -425 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 6) (pt 0 mils -500 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -525 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 7) (pt 0 mils -600 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -625 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 8) (pt 0 mils -700 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -725 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 9) (pt 0 mils -800 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -825 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 10) (pt 0 mils -900 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -925 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 11) (pt 0 mils -1000 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -1025 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 12) (pt 400 mils -1700 mils) (rotation 90) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 425 mils -1470 mils) (rotation 90]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 13) (pt 500 mils -1700 mils) (rotation 90) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 525 mils -1470 mils) (rotation 90]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 14) (pt 600 mils -1700 mils) (rotation 90) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 625 mils -1470 mils) (rotation 90]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 15) (pt 700 mils -1700 mils) (rotation 90) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 725 mils -1470 mils) (rotation 90]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 16) (pt 800 mils -1700 mils) (rotation 90) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 825 mils -1470 mils) (rotation 90]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 17) (pt 1300 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 18) (pt 1300 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 19) (pt 1300 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 20) (pt 1300 mils -300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -325 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 21) (pt 1300 mils -400 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -425 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 22) (pt 1300 mils -500 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -525 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 23) (pt 1300 mils -600 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -625 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 24) (pt 1300 mils -700 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -725 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 25) (pt 1300 mils -800 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -825 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 26) (pt 1300 mils -900 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -925 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 27) (pt 1300 mils -1000 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1070 mils -1025 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 28) (pt 400 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 425 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 29) (pt 500 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 525 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 30) (pt 600 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 625 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 31) (pt 700 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 725 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 32) (pt 800 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 825 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 33) (pt 900 mils 600 mils) (rotation 270) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 925 mils 370 mils) (rotation 90]) (justify "Right") (textStyleRef "Default"))
		))
		(line (pt 200 mils 400 mils) (pt 1100 mils 400 mils) (width 6 mils))
		(line (pt 1100 mils 400 mils) (pt 1100 mils -1500 mils) (width 6 mils))
		(line (pt 1100 mils -1500 mils) (pt 200 mils -1500 mils) (width 6 mils))
		(line (pt 200 mils -1500 mils) (pt 200 mils 400 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1150 mils 600 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "PI4IOE5V96224ZLEX" (originalName "PI4IOE5V96224ZLEX") (compHeader (numPins 33) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "AD2") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "__RESET") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "IO0_0") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "4" (pinName "IO0_1") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "5" (pinName "IO0_2") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "6" (pinName "IO0_3") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "7" (pinName "IO0_4") (partNum 1) (symPinNum 7) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "8" (pinName "IO0_5") (partNum 1) (symPinNum 8) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "9" (pinName "IO0_6") (partNum 1) (symPinNum 9) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "10" (pinName "IO0_7") (partNum 1) (symPinNum 10) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "11" (pinName "IO1_0") (partNum 1) (symPinNum 11) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "12" (pinName "IO1_1") (partNum 1) (symPinNum 12) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "13" (pinName "IO1_2") (partNum 1) (symPinNum 13) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "14" (pinName "IO1_3") (partNum 1) (symPinNum 14) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "15" (pinName "IO1_4") (partNum 1) (symPinNum 15) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "16" (pinName "IO1_5") (partNum 1) (symPinNum 16) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "27" (pinName "__INT") (partNum 1) (symPinNum 17) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "26" (pinName "IO2_7") (partNum 1) (symPinNum 18) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "25" (pinName "IO2_6") (partNum 1) (symPinNum 19) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "24" (pinName "IO2_5") (partNum 1) (symPinNum 20) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "23" (pinName "IO2_4") (partNum 1) (symPinNum 21) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "22" (pinName "IO2_3") (partNum 1) (symPinNum 22) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "21" (pinName "IO2_2") (partNum 1) (symPinNum 23) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "20" (pinName "IO2_1") (partNum 1) (symPinNum 24) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "19" (pinName "IO2_0") (partNum 1) (symPinNum 25) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "18" (pinName "IO1_7") (partNum 1) (symPinNum 26) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "17" (pinName "IO1_6") (partNum 1) (symPinNum 27) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "33" (pinName "GND") (partNum 1) (symPinNum 28) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "32" (pinName "AD1") (partNum 1) (symPinNum 29) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "31" (pinName "AD0") (partNum 1) (symPinNum 30) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "30" (pinName "VCC") (partNum 1) (symPinNum 31) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "29" (pinName "SDA") (partNum 1) (symPinNum 32) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "28" (pinName "SCL") (partNum 1) (symPinNum 33) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "PI4IOE5V96224ZLEX"))
		(attachedPattern (patternNum 1) (patternName "QFN40P300X600X80-33N")
			(numPads 33)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
				(padNum 7) (compPinRef "7")
				(padNum 8) (compPinRef "8")
				(padNum 9) (compPinRef "9")
				(padNum 10) (compPinRef "10")
				(padNum 11) (compPinRef "11")
				(padNum 12) (compPinRef "12")
				(padNum 13) (compPinRef "13")
				(padNum 14) (compPinRef "14")
				(padNum 15) (compPinRef "15")
				(padNum 16) (compPinRef "16")
				(padNum 17) (compPinRef "17")
				(padNum 18) (compPinRef "18")
				(padNum 19) (compPinRef "19")
				(padNum 20) (compPinRef "20")
				(padNum 21) (compPinRef "21")
				(padNum 22) (compPinRef "22")
				(padNum 23) (compPinRef "23")
				(padNum 24) (compPinRef "24")
				(padNum 25) (compPinRef "25")
				(padNum 26) (compPinRef "26")
				(padNum 27) (compPinRef "27")
				(padNum 28) (compPinRef "28")
				(padNum 29) (compPinRef "29")
				(padNum 30) (compPinRef "30")
				(padNum 31) (compPinRef "31")
				(padNum 32) (compPinRef "32")
				(padNum 33) (compPinRef "33")
			)
		)
		(attr "Mouser Part Number" "729-I4IOE5V96224ZLEX")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Diodes-Incorporated/PI4IOE5V96224ZLEX?qs=0lQeLiL1qybZKU%252B6WN8aKg%3D%3D")
		(attr "Manufacturer_Name" "Diodes Inc.")
		(attr "Manufacturer_Part_Number" "PI4IOE5V96224ZLEX")
		(attr "Description" "Interface - I/O Expanders 24-bit I2C-bus I/O Expander")
		(attr "Datasheet Link" "https://www.diodes.com/assets/Datasheets/PI4IOE5V96224.pdf")
		(attr "Height" "0.8 mm")
	)

)
