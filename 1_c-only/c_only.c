#include "pico/stdlib.h"

int main() {
    const uint pin_map_display_to_pico[] = {
        0,
        16, 17, 18, 19, 20, 21, 22,
        9, 10, 11, 12, 13, 14, 15,
    };

    const uint A  = pin_map_display_to_pico[13];
    const uint B  = pin_map_display_to_pico[9];
    const uint C  = pin_map_display_to_pico[4];
    const uint D  = pin_map_display_to_pico[2];
    const uint E  = pin_map_display_to_pico[1];
    const uint F  = pin_map_display_to_pico[12];
    const uint G  = pin_map_display_to_pico[5];
    const uint DP = pin_map_display_to_pico[3];
    const uint D5 = pin_map_display_to_pico[8];

    const uint COM_1    = pin_map_display_to_pico[14];
    const uint COM_2    = pin_map_display_to_pico[11];
    const uint COM_3    = pin_map_display_to_pico[10];
    const uint COM_4    = pin_map_display_to_pico[6];
    const uint COM_DOTS = pin_map_display_to_pico[7];

    stdio_init_all();
    for (int i = 1; i < sizeof(pin_map_display_to_pico) / sizeof(pin_map_display_to_pico[0]); ++i) {
        gpio_init(pin_map_display_to_pico[i]);
        gpio_set_dir(pin_map_display_to_pico[i], GPIO_OUT);
    }

    gpio_put(COM_DOTS, 0);
    gpio_put(D5, 1);

    while (true) {
        gpio_put(COM_1, 0);
        gpio_put(COM_2, 1);
        gpio_put(COM_3, 1);
        gpio_put(COM_4, 1);

        gpio_put(A, 0);
        gpio_put(B, 1);
        gpio_put(C, 1);
        gpio_put(D, 0);
        gpio_put(E, 0);
        gpio_put(F, 0);
        gpio_put(G, 0);
        gpio_put(DP, 0);

        sleep_ms(2);

        gpio_put(COM_1, 1);
        gpio_put(COM_2, 0);
        gpio_put(COM_3, 1);
        gpio_put(COM_4, 1);

        gpio_put(A, 1);
        gpio_put(B, 1);
        gpio_put(C, 0);
        gpio_put(D, 1);
        gpio_put(E, 1);
        gpio_put(F, 0);
        gpio_put(G, 1);
        gpio_put(DP, 0);

        sleep_ms(2);

        gpio_put(COM_1, 1);
        gpio_put(COM_2, 1);
        gpio_put(COM_3, 0);
        gpio_put(COM_4, 1);

        gpio_put(A, 1);
        gpio_put(B, 1);
        gpio_put(C, 1);
        gpio_put(D, 1);
        gpio_put(E, 0);
        gpio_put(F, 0);
        gpio_put(G, 1);
        gpio_put(DP, 0);

        sleep_ms(2);

        gpio_put(COM_1, 1);
        gpio_put(COM_2, 1);
        gpio_put(COM_3, 1);
        gpio_put(COM_4, 0);

        gpio_put(A, 0);
        gpio_put(B, 1);
        gpio_put(C, 1);
        gpio_put(D, 0);
        gpio_put(E, 0);
        gpio_put(F, 1);
        gpio_put(G, 1);
        gpio_put(DP, 1);

        sleep_ms(2);
    }
}
