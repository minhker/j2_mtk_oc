#ifndef _DIMMING_PARAM_H_
#define _DIMMING_PARAM_H_
#include "dimming_core.h"

struct gamma_correction_input {
	u32 luminance;
	u32 aor;
	u32 base_luminamce;
	int gamma;
	s32 gray_scale_offset[9];
	s32 rgb_color_offset[8][MAX_COLOR];
};

const int tp[] = {0, 3, 11, 23, 35, 51, 87, 151, 203, 255};
const int mtp_base[][MAX_COLOR] = {
	{0, 0, 0},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x80, 0x80, 0x80},
	{0x100, 0x100, 0x100}
};

const s64 VREGOUT = 27262976LL;
const int LUT_GAMMA = 220;

const struct coeff_t v_coeff[] = {
	{0, 860},
	{64, 320},
	{64, 320},
	{64, 320},
	{64, 320},
	{64, 320},
	{64, 320},
	{64, 320},
	{64, 320},
	{72, 860},
};

const struct coeff_t vt_coeff[16] = {
	{0, 860},
	{12, 860},
	{24, 860},
	{36, 860},
	{48, 860},
	{60, 860},
	{72, 860},
	{84, 860},
	{96, 860},
	{108, 860},
	{138, 860},
	{148, 860},
	{158, 860},
	{168, 860},
	{178, 860},
	{186, 860},
};

const int gray_scale_offset_order[] = {
	9, 8, 7, 6, 5, 4, 3, 2, 1
};

const int rgb_color_offset_order[] = {
	9, 8, 7, 6, 5, 4, 3, 2
};

/* luminance, base_luminance, aor, gamma, gray_scale_offset, color_shift_offset */
struct gamma_correction_input gamma_correction_input_lut[] = {
	{5, 0x074C, 114, 215, {0, 3, 1, 1, 4, 6, 8, 10, 12}, {{-1, -2, 1}, {-1, -1, -1}, {1, 0, 1}, {3, 1, 3}, {3, 1, 3}, {5, 2, 4}, {10, 6, 6}, {17, 11, 10}}},
	{6, 0x0742, 114, 215, {0, 1, -3, -2, 2, 4, 6, 8, 10}, {{1, 0, 3}, {1, 1, 1}, {2, 1, 2}, {2, 1, 2}, {3, 2, 3}, {4, 1, 3}, {14, 8, 7}, {17, 11, 10}}},
	{7, 0x0733, 114, 215, {0, 2, -1, -1, 2, 3, 7, 7, 8}, {{0, -1, 2}, {0, 0, 0}, {2, 1, 2}, {2, 1, 2}, {4, 1, 3}, {5, 4, 4}, {3, -3, 0}, {28, 22, 16}}},
	{8, 0x071E, 114, 215, {0, 5, 4, 3, 4, 5, 8, 7, 8}, {{-4, -4, -2}, {-2, -3, -2}, {-1, -2, 0}, {1, -1, 1}, {2, 1, 3}, {4, 2, 3}, {3, -2, 1}, {30, 26, 18}}},
	{9, 0x0714, 114, 215, {0, 1, -4, -3, 0, 1, 5, 8, 8}, {{0, 0, 2}, {1, 1, 1}, {4, 3, 3}, {3, 1, 1}, {3, 3, 4}, {5, 5, 4}, {3, -2, -1}, {6, 0, 2}}},
	{10, 0x0705, 114, 215, {0, 2, 0, -1, 1, 2, 5, 8, 8}, {{-1, -1, 1}, {0, 0, 0}, {1, 0, 1}, {3, 1, 2}, {3, 3, 4}, {4, 2, 2}, {6, 3, 2}, {6, -2, 2}}},
	{11, 0x06F6, 114, 215, {0, 1, -3, -4, -1, 0, 4, 7, 8}, {{0, 0, 2}, {1, 1, 1}, {3, 2, 3}, {6, 4, 4}, {3, 3, 4}, {4, 4, 2}, {2, -1, -1}, {4, -2, 2}}},
	{12, 0x06E7, 114, 215, {0, 2, -1, -3, -1, 0, 3, 6, 8}, {{0, 0, 2}, {0, 0, 0}, {1, 1, 1}, {6, 4, 5}, {4, 4, 5}, {4, 4, 2}, {7, 5, 2}, {5, -4, 1}}},
	{13, 0x06D6, 114, 215, {0, 2, -1, -2, 0, 1, 4, 6, 7}, {{-1, -1, 1}, {1, 1, 1}, {1, 0, 0}, {3, 3, 3}, {3, 3, 4}, {1, 1, 1}, {5, 2, 0}, {3, -4, 0}}},
	{14, 0x06C8, 114, 215, {0, 2, -2, -2, -1, 0, 3, 5, 7}, {{0, 0, 2}, {1, 1, 1}, {2, 1, 1}, {2, 1, 1}, {6, 6, 6}, {3, 3, 2}, {5, 2, 0}, {10, 2, 4}}},
	{15, 0x06BA, 114, 215, {0, 2, -1, -2, -1, 0, 3, 5, 7}, {{0, 0, 2}, {0, 0, 0}, {2, 1, 1}, {2, 2, 2}, {7, 6, 7}, {2, 2, 1}, {5, 1, 0}, {8, 2, 3}}},
	{16, 0x06AB, 114, 215, {0, 2, -1, -2, 0, 0, 3, 5, 7}, {{0, 0, 2}, {0, 0, 0}, {2, 1, 1}, {2, 2, 2}, {2, 2, 3}, {6, 6, 3}, {4, 1, 0}, {7, 0, 2}}},
	{17, 0x06A1, 114, 215, {0, 3, 0, -1, 0, 0, 3, 5, 0}, {{-1, -1, 1}, {-1, 0, -1}, {3, 1, 1}, {1, 1, 1}, {5, 4, 5}, {5, 5, 2}, {3, 0, -1}, {7, -1, 2}}},
	{19, 0x0682, 114, 215, {0, 2, -1, -3, -1, -1, 2, 4, 6}, {{0, 0, 1}, {0, 0, 0}, {2, 1, 1}, {4, 4, 5}, {2, 3, 3}, {7, 6, 3}, {2, 0, -2}, {5, -2, 0}}},
	{20, 0x066B, 114, 215, {0, 3, 0, -1, 0, 0, 2, 4, 6}, {{-1, -1, 0}, {0, 0, 0}, {1, 0, -1}, {2, 2, 3}, {3, 3, 3}, {5, 4, 2}, {7, 6, 2}, {5, -3, 0}}},
	{21, 0x0657, 114, 215, {0, 2, -2, -2, -1, -1, 2, 4, 7}, {{0, 0, 1}, {1, 1, 1}, {3, 2, 1}, {2, 2, 2}, {4, 4, 5}, {6, 7, 2}, {3, 1, -2}, {6, 0, 0}}},
	{22, 0x0642, 114, 215, {0, 2, -1, -2, -1, -1, 2, 4, 7}, {{0, 0, 1}, {1, 1, 1}, {2, 1, 1}, {3, 3, 3}, {6, 6, 6}, {6, 7, 2}, {3, 2, -2}, {6, 3, 0}}},
	{24, 0x060D, 114, 215, {0, 3, 2, 1, 2, 2, 4, 6, 8}, {{-1, -1, 0}, {0, 0, 0}, {0, 0, -1}, {2, 1, 2}, {1, 1, 1}, {2, 3, 2}, {5, 4, 0}, {6, 2, 0}}},
	{25, 0x05F8, 114, 215, {0, 2, -1, -1, 0, 0, 3, 5, 7}, {{0, 0, 1}, {1, 1, 1}, {3, 3, 2}, {2, 2, 2}, {4, 5, 4}, {5, 6, 1}, {4, 2, -2}, {7, 4, 0}}},
	{27, 0x05CE, 114, 215, {0, 3, 2, 2, 2, 1, 4, 6, 8}, {{-1, 0, 0}, {0, 0, 0}, {1, 1, 0}, {1, 1, 1}, {3, 3, 3}, {5, 7, 3}, {3, 2, -3}, {5, 3, -1}}},
	{29, 0x0598, 114, 215, {0, 2, 0, 0, 1, 1, 4, 6, 8}, {{0, 1, 1}, {1, 1, 1}, {2, 2, 1}, {2, 2, 2}, {3, 3, 3}, {3, 4, 0}, {2, 3, -3}, {5, 3, -2}}},
	{30, 0x057A, 114, 215, {0, 2, 1, 1, 1, 1, 4, 6, 8}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {3, 3, 3}, {4, 4, 4}, {4, 5, 0}, {2, 3, -4}, {6, 4, -1}}},
	{32, 0x0544, 114, 215, {0, 4, 3, 3, 2, 1, 4, 6, 8}, {{-1, 0, 0}, {0, 0, 0}, {1, 0, 0}, {2, 2, 2}, {5, 5, 5}, {6, 7, 3}, {1, 2, -5}, {6, 5, -1}}},
	{34, 0x0522, 114, 215, {0, 3, 2, 2, 2, 1, 4, 6, 8}, {{0, 1, 1}, {0, 0, 0}, {2, 2, 1}, {2, 2, 2}, {3, 4, 3}, {6, 7, 3}, {1, 2, -5}, {4, 3, -2}}},
	{37, 0x04E4, 114, 215, {0, 3, 2, 2, 2, 1, 3, 5, 7}, {{0, 1, 1}, {0, 0, 0}, {1, 1, 0}, {3, 3, 3}, {2, 3, 2}, {6, 7, 3}, {5, 7, -1}, {5, 4, -2}}},
	{39, 0x04BE, 114, 215, {0, 3, 2, 2, 2, 1, 3, 5, 7}, {{-1, 0, 0}, {1, 1, 1}, {1, 1, 0}, {2, 2, 2}, {3, 4, 3}, {4, 6, 2}, {6, 7, -1}, {3, 2, -3}}},
	{41, 0x0495, 114, 215, {0, 3, 2, 2, 2, 1, 3, 5, 7}, {{-1, 0, 0}, {1, 1, 1}, {1, 1, 0}, {2, 2, 2}, {3, 4, 3}, {4, 6, 2}, {5, 6, -1}, {2, 1, -4}}},
	{44, 0x0456, 114, 215, {0, 3, 2, 2, 2, 1, 3, 5, 7}, {{-1, 0, 0}, {1, 1, 1}, {1, 1, 0}, {2, 2, 2}, {2, 3, 2}, {5, 6, 3}, {4, 6, -2}, {1, -1, -4}}},
	{47, 0x0421, 114, 215, {0, 3, 2, 2, 2, 1, 3, 4, 6}, {{-1, 0, 0}, {1, 1, 1}, {1, 1, 0}, {2, 2, 2}, {2, 3, 2}, {5, 6, 3}, {3, 5, -2}, {7, 6, -1}}},
	{50, 0x03E3, 114, 215, {0, 3, 2, 1, 1, 1, 3, 4, 6}, {{-1, 0, 0}, {0, 1, 0}, {2, 1, 1}, {4, 5, 4}, {3, 3, 3}, {1, 2, -1}, {4, 5, -2}, {5, 4, -2}}},
	{53, 0x03A5, 114, 215, {0, 2, 1, 0, 0, 0, 2, 3, 5}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {4, 5, 4}, {6, 5, 6}, {2, 4, -1}, {5, 5, -2}, {5, 6, 1}}},
	{56, 0x0364, 114, 215, {0, 2, 1, 0, 0, 0, 2, 3, 5}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {4, 5, 4}, {5, 5, 5}, {2, 3, -1}, {4, 5, -2}, {5, 5, 1}}},
	{60, 0x0312, 114, 215, {0, 2, 1, 0, 0, 0, 2, 3, 5}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {4, 5, 4}, {5, 4, 5}, {2, 4, -1}, {4, 4, -2}, {2, 4, 0}}},
	{64, 0x02D5, 114, 215, {0, 2, 1, 0, 0, -1, 1, 2, 4}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {4, 5, 4}, {5, 5, 5}, {8, 9, 4}, {1, 4, -4}, {4, 5, 2}}},
	{68, 0x02C5, 121, 215, {0, 3, 1, 1, 0, 0, 1, 3, 5}, {{0, 1, 1}, {0, 1, 1}, {3, 2, 1}, {2, 3, 2}, {5, 5, 5}, {5, 7, 2}, {3, 3, -3}, {1, 1, -1}}},
	{72, 0x02C5, 127, 215, {0, 4, 4, 3, 2, 2, 3, 4, 6}, {{-1, 0, 0}, {0, 0, 0}, {1, 1, 1}, {2, 1, 1}, {1, 1, 2}, {3, 3, 1}, {2, 4, -1}, {4, 4, -1}}},
	{77, 0x02C5, 135, 215, {0, 2, 3, 3, 1, 1, 1, 2, 5}, {{0, 0, 1}, {0, 1, 1}, {1, 1, 0}, {2, 2, 2}, {3, 3, 3}, {6, 6, 4}, {4, 5, -2}, {4, 6, 1}}},
	{82, 0x02C5, 144, 215, {0, 3, 3, 2, 1, 1, 2, 3, 5}, {{-1, 0, 0}, {0, 1, 1}, {1, 2, 1}, {3, 3, 3}, {1, 1, 2}, {5, 6, 3}, {1, 2, -2}, {2, 3, -2}}},
	{87, 0x02C5, 151, 215, {0, 4, 4, 3, 1, 1, 2, 3, 5}, {{0, 0, 1}, {0, 1, 1}, {1, 1, 0}, {2, 3, 2}, {3, 3, 3}, {4, 4, 2}, {4, 6, -1}, {1, 1, -3}}},
	{93, 0x02C5, 159, 215, {0, 2, 3, 3, 1, 0, 0, 2, 4}, {{1, 1, 2}, {1, 1, 1}, {1, 2, 1}, {2, 2, 2}, {5, 4, 4}, {7, 8, 5}, {6, 8, 0}, {1, 2, -1}}},
	{98, 0x02C5, 169, 215, {0, 3, 4, 3, 1, 1, 1, 3, 5}, {{-1, 0, 0}, {0, 1, 1}, {2, 3, 1}, {2, 2, 2}, {2, 3, 2}, {5, 5, 3}, {7, 9, 1}, {-1, -1, -4}}},
	{105, 0x02C5, 179, 215, {0, 3, 5, 3, 1, 0, 1, 2, 5}, {{0, 0, 0}, {0, 1, 1}, {1, 1, 1}, {3, 2, 2}, {3, 3, 3}, {6, 7, 5}, {1, 2, -3}, {3, 4, -1}}},
	{111, 0x02C5, 189, 215, {0, 3, 4, 3, 2, 1, 1, 2, 5}, {{0, 0, 1}, {0, 1, 1}, {1, 1, 0}, {2, 1, 1}, {4, 4, 4}, {5, 6, 3}, {4, 6, 0}, {2, 3, -1}}},
	{119, 0x02C5, 201, 215, {0, 4, 7, 5, 1, 1, 1, 3, 5}, {{-1, 0, 0}, {0, 0, 0}, {0, 1, 0}, {3, 2, 2}, {6, 6, 6}, {3, 4, 1}, {2, 4, -1}, {0, 1, -2}}},
	{126, 0x02C5, 212, 215, {0, 3, 4, 3, 1, 0, 1, 2, 3}, {{0, 0, 1}, {0, 1, 1}, {2, 1, 1}, {3, 2, 2}, {3, 4, 3}, {6, 7, 4}, {2, 3, -1}, {6, 7, 1}}},
	{134, 0x02C5, 224, 215, {0, 4, 6, 4, 2, 0, 0, 1, 3}, {{0, 0, 1}, {0, 2, 1}, {0, 1, 0}, {2, 2, 2}, {3, 2, 3}, {7, 7, 6}, {6, 7, 2}, {4, 6, 0}}},
	{143, 0x02C5, 238, 215, {0, 3, 4, 2, 0, -1, -1, 0, 2}, {{0, 0, 2}, {1, 1, 0}, {2, 2, 1}, {3, 4, 3}, {5, 5, 5}, {9, 10, 6}, {7, 9, 2}, {6, 8, 2}}},
	{152, 0x02C5, 251, 215, {0, 2, 2, 0, -2, -3, -2, 0, 2}, {{1, 1, 2}, {1, 1, 1}, {2, 3, 1}, {4, 4, 4}, {7, 8, 6}, {8, 9, 5}, {4, 5, 0}, {4, 7, 1}}},
	{162, 0x02C5, 264, 215, {0, 2, 4, 3, 1, 0, 0, 1, 2}, {{0, 0, 2}, {1, 1, 1}, {2, 2, 1}, {2, 3, 2}, {3, 4, 4}, {3, 4, 2}, {6, 8, 3}, {7, 8, 3}}},
	{172, 0x0278, 264, 215, {0, 2, 4, 3, 1, 0, 0, 1, 2}, {{0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {2, 3, 2}, {3, 4, 3}, {4, 5, 4}, {6, 7, 2}, {5, 6, 2}}},
	{183, 0x0215, 264, 215, {0, 2, 3, 3, 1, 0, 0, 1, 2}, {{0, 0, 1}, {0, 1, 1}, {2, 1, 1}, {2, 2, 2}, {3, 3, 3}, {3, 5, 2}, {6, 7, 3}, {4, 5, 2}}},
	{195, 0x01B6, 264, 215, {0, 2, 3, 3, 1, 0, 0, 1, 2}, {{0, 0, 1}, {0, 1, 1}, {1, 0, 0}, {2, 2, 2}, {4, 4, 4}, {3, 4, 2}, {6, 7, 3}, {2, 3, 0}}},
	{207, 0x0159, 264, 215, {0, 2, 2, 2, 0, -1, -1, 0, 1}, {{0, 0, 1}, {0, 1, 1}, {2, 1, 1}, {2, 2, 2}, {3, 3, 4}, {5, 5, 3}, {7, 9, 4}, {4, 4, 2}}},
	{220, 0x00F5, 264, 215, {0, 2, 2, 2, 0, -1, -1, 0, 0}, {{0, 0, 1}, {0, 1, 1}, {2, 1, 1}, {2, 2, 2}, {3, 2, 3}, {5, 6, 4}, {6, 7, 3}, {3, 4, 2}}},
	{234, 0x0084, 264, 215, {0, 1, 2, 1, -1, -2, -1, 0, 0}, {{0, 0, 1}, {1, 1, 1}, {2, 2, 1}, {2, 3, 2}, {4, 4, 4}, {6, 6, 4}, {2, 3, 0}, {2, 3, 2}}},
	{249, 0x0010, 264, 215, {0, 1, 3, 3, 2, 1, 1, 2, 3}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{265, 0x0010, 278, 215, {0, 2, 3, 2, 2, 1, 1, 2, 2}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{282, 0x0010, 296, 215, {0, 0, 2, 1, 2, 2, 1, 1, 2}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{300, 0x0010, 310, 215, {0, -1, 1, 1, 1, 1, 0, 1, 1}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{316, 0x0010, 325, 215, {0, -1, 0, 0, 1, 0, 0, 1, 1}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{333, 0x0010, 342, 215, {0, -1, 0, -1, -1, -1, 0, 0, 1}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
	{360, 0x0010, 360, 220, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},
};

#endif	/* _DIMMING_PARAM_H_ */
