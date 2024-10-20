#pragma once

#include "Uhrtype.hpp"

/*
 *           Layout Front
 *                COL
 *       9 8 7 6 5 4 3 2 1 0 
 * ROW + - - - - - - - - - - 
 *  0  | E S K I S R F Ü N F
 *  1  | Z E H N C D R E I W
 *  2  | Z R Q V I E R T E L
 *  3  | H A L B P S E C H S
 *  4  | W N A C H T V O R T
 *  5  | E L F O S I E B E N
 *  6  | Y A C H T Z E I N S
 *  7  | Z W O E Z W Ö L F U
 *  8  | W Z W A N Z I G R Q
 *  9  | X N E U N T U H R O
 */

class De10x10saarlaendisch_t : public iUhrType {
public:
    virtual LanguageAbbreviation usedLang() override {
        return LanguageAbbreviation::DE;
    };

    virtual const uint16_t getFrontMatrixIndex(uint8_t row,
                                               uint8_t col) override {
        
        uint8_t newColsWordMatrix = colsWordMatrix();
        uint16_t numPixelsWordMatrix = rowsWordMatrix() * colsWordMatrix();

        if (G.buildTypeDef == BuildTypeDef::DoubleResM1) {
            newColsWordMatrix = 2 * colsWordMatrix() - 1;
            numPixelsWordMatrix = rowsWordMatrix() * newColsWordMatrix;
            col *= 2;
        }
       
        // if ( row % 2 != 0) {
        //     col = newColsWordMatrix - col - 1;
        // }

        if (row % 1 != 0) {
            col = col + 1 - newColsWordMatrix;
        }

        uint16_t returnValue = col + (row * newColsWordMatrix);

        if (returnValue > numPixelsWordMatrix) {
            Serial.println(
                "[ERROR] getFrontMatrixIndex() returnValue out of Bounds");
        }

        return returnValue;
    };

    virtual const uint8_t rowsWordMatrix() override { return 10; };

    //------------------------------------------------------------------------------

    virtual const uint8_t colsWordMatrix() override { return 10; };

    //------------------------------------------------------------------------------

    virtual const bool hasDreiviertel() override { return true; }

    //------------------------------------------------------------------------------

    virtual const bool hasZwanzig() override { return true; }

    //--------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::es_ist:
            setFrontMatrixWord(0, 8, 9);
            setFrontMatrixWord(0, 5, 6);
            break;

        case FrontWord::nach:
        case FrontWord::v_nach:
            setFrontMatrixWord(4, 5, 8);
            break;

        case FrontWord::vor:
        case FrontWord::v_vor:
            setFrontMatrixWord(4, 1, 3);
            break;

        case FrontWord::viertel:
            setFrontMatrixWord(2, 0, 6);
            break;

        case FrontWord::dreiviertel:
            setFrontMatrixWord(1, 1, 4);
            setFrontMatrixWord(2, 2, 6);
            break;

        case FrontWord::min_5:
            setFrontMatrixWord(0, 0, 3);
            break;

        case FrontWord::min_10:
            setFrontMatrixWord(1, 6, 9);
            break;

        case FrontWord::min_20:
            setFrontMatrixWord(8, 2, 8);
            break;

        case FrontWord::halb:
            setFrontMatrixWord(3, 6, 9);
            break;

        case FrontWord::eins:
            setFrontMatrixWord(6, 1, 3);
            break;

        case FrontWord::uhr:
            setFrontMatrixWord(9, 1, 3);
            break;

        case FrontWord::hour_1:
            setFrontMatrixWord(6, 1, 3);
            break;

        case FrontWord::hour_2:
            setFrontMatrixWord(7, 7, 9);
            break;

        case FrontWord::hour_3:
            setFrontMatrixWord(1, 1, 4);
            break;

        case FrontWord::hour_4:
            setFrontMatrixWord(2, 3, 6);
            break;

        case FrontWord::hour_5:
            setFrontMatrixWord(0, 0, 3);
            break;

        case FrontWord::hour_6:
            setFrontMatrixWord(3, 0, 4);
            break;

        case FrontWord::hour_7:
            setFrontMatrixWord(5, 0, 5);
            break;

        case FrontWord::hour_8:
            setFrontMatrixWord(6, 5, 8);
            break;

        case FrontWord::hour_9:
            setFrontMatrixWord(9, 5, 8);
            break;

        case FrontWord::hour_10:
            setFrontMatrixWord(1, 6, 9);
            break;

        case FrontWord::hour_11:
            setFrontMatrixWord(5, 7, 9);
            break;

        case FrontWord::hour_12:
            setFrontMatrixWord(7, 1, 5);
            break;

        default:
            break;
        };
    };
};

De10x10saarlaendisch_t _de10x10saarlaendisch;