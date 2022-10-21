#include "pico/stdlib.h"
#include "basic_pio.pio.h"

#define START_PIN 9

#define A  1 << (14 - START_PIN)
#define B  1 << (10 - START_PIN)
#define C  1 << (19 - START_PIN)
#define D  1 << (17 - START_PIN)
#define E  1 << (16 - START_PIN)
#define F  1 << (13 - START_PIN)
#define G  1 << (20 - START_PIN)
#define DP 1 << (18 - START_PIN)
#define D5 1 << (9 - START_PIN)

#define COM_1    1 << (15 - START_PIN)
#define COM_2    1 << (12 - START_PIN)
#define COM_3    1 << (11 - START_PIN)
#define COM_4    1 << (21 - START_PIN)
#define COM_DOTS 1 << (22 - START_PIN)

const uint one   = B|C|D5;
const uint two   = A|B|D|E|G;
const uint three = A|B|C|D|G;
const uint four  = B|C|F|G|DP;

const uint com_1 = COM_2|COM_3|COM_4;
const uint com_2 = COM_1|COM_3|COM_4|COM_DOTS;
const uint com_3 = COM_1|COM_2|COM_4|COM_DOTS;
const uint com_4 = COM_1|COM_2|COM_3|COM_DOTS;

int main() {
    const PIO pio = pio0;

    const uint offset = pio_add_program(pio, &basic_pio_program);
    const uint sm = pio_claim_unused_sm(pio, true);

    basic_pio_program_init(pio, sm, offset, START_PIN);

    while (true) {
        pio_sm_put(pio, sm, com_1|one);
        sleep_ms(2);
        pio_sm_put(pio, sm, com_2|two);
        sleep_ms(2);
        pio_sm_put(pio, sm, com_3|three);
        sleep_ms(2);
        pio_sm_put(pio, sm, com_4|four);
        sleep_ms(2);
    }
}
