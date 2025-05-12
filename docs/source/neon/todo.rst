
#include <stdio.h>
#include <arm_neon.h>

int main() {
    // 定义一个包含 8 个半精度浮点数的数组
    float16_t data[8] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};

    // 使用 vld1q_f16 加载数据到 NEON 寄存器
    float16x8_t vec = vld1q_f16(data);

    // 打印加载的数据
    for (int i = 0; i < 8; i++) {
        printf("Element %d: %f\n", i, (float)vgetq_lane_f16(vec, i));
    }

    return 0;
}
