#include "exhanzi.h"

struct hanzi_index hz_index[HZIDXSIZE];
int hz_index_len;

/*
   U+FDD0 (Noncharacter) is used.
 */
struct hanzi_index HZ_RADICAL[]={
  {{0x2F00, L'\0'}, {0xFDD0, 0x4E00, L'\0'}}, /* 一 */
  {{0x2F01, L'\0'}, {0xFDD0, 0x4E28, L'\0'}}, /* 丨 */
  {{0x2F02, L'\0'}, {0xFDD0, 0x4E36, L'\0'}}, /* 丶 */
  {{0x2F03, L'\0'}, {0xFDD0, 0x4E3F, L'\0'}}, /* 丿 */
  {{0x2F04, L'\0'}, {0xFDD0, 0x4E59, L'\0'}}, /* 乙 */
  {{0x2F05, L'\0'}, {0xFDD0, 0x4E85, L'\0'}}, /* 亅 */
  {{0x2F06, L'\0'}, {0xFDD0, 0x4E8C, L'\0'}}, /* 二 */
  {{0x2F07, L'\0'}, {0xFDD0, 0x4EA0, L'\0'}}, /* 亠 */
  {{0x2F08, L'\0'}, {0xFDD0, 0x4EBA, L'\0'}}, /* 人 */
  {{0x2F09, L'\0'}, {0xFDD0, 0x513F, L'\0'}}, /* 儿 */
  {{0x2F0A, L'\0'}, {0xFDD0, 0x5165, L'\0'}}, /* 入 */
  {{0x2F0B, L'\0'}, {0xFDD0, 0x516B, L'\0'}}, /* 八 */
  {{0x2F0C, L'\0'}, {0xFDD0, 0x5182, L'\0'}}, /* 冂 */
  {{0x2F0D, L'\0'}, {0xFDD0, 0x5196, L'\0'}}, /* 冖 */
  {{0x2F0E, L'\0'}, {0xFDD0, 0x51AB, L'\0'}}, /* 冫 */
  {{0x2F0F, L'\0'}, {0xFDD0, 0x51E0, L'\0'}}, /* 几 */
  {{0x2F10, L'\0'}, {0xFDD0, 0x51F5, L'\0'}}, /* 凵 */
  {{0x2F11, L'\0'}, {0xFDD0, 0x5200, L'\0'}}, /* 刀 */
  {{0x2F12, L'\0'}, {0xFDD0, 0x529B, L'\0'}}, /* 力 */
  {{0x2F13, L'\0'}, {0xFDD0, 0x52F9, L'\0'}}, /* 勹 */
  {{0x2F14, L'\0'}, {0xFDD0, 0x5315, L'\0'}}, /* 匕 */
  {{0x2F15, L'\0'}, {0xFDD0, 0x531A, L'\0'}}, /* 匚 */
  {{0x2F16, L'\0'}, {0xFDD0, 0x5338, L'\0'}}, /* 匸 */
  {{0x2F17, L'\0'}, {0xFDD0, 0x5341, L'\0'}}, /* 十 */
  {{0x2F18, L'\0'}, {0xFDD0, 0x535C, L'\0'}}, /* 卜 */
  {{0x2F19, L'\0'}, {0xFDD0, 0x5369, L'\0'}}, /* 卩 */
  {{0x2F1A, L'\0'}, {0xFDD0, 0x5382, L'\0'}}, /* 厂 */
  {{0x2F1B, L'\0'}, {0xFDD0, 0x53B6, L'\0'}}, /* 厶 */
  {{0x2F1C, L'\0'}, {0xFDD0, 0x53C8, L'\0'}}, /* 又 */
  {{0x2F1D, L'\0'}, {0xFDD0, 0x53E3, L'\0'}}, /* 口 */
  {{0x2F1E, L'\0'}, {0xFDD0, 0x56D7, L'\0'}}, /* 囗 */
  {{0x2F1F, L'\0'}, {0xFDD0, 0x571F, L'\0'}}, /* 土 */
  {{0x2F20, L'\0'}, {0xFDD0, 0x58EB, L'\0'}}, /* 士 */
  {{0x2F21, L'\0'}, {0xFDD0, 0x5902, L'\0'}}, /* 夂 */
  {{0x2F22, L'\0'}, {0xFDD0, 0x590A, L'\0'}}, /* 夊 */
  {{0x2F23, L'\0'}, {0xFDD0, 0x5915, L'\0'}}, /* 夕 */
  {{0x2F24, L'\0'}, {0xFDD0, 0x5927, L'\0'}}, /* 大 */
  {{0x2F25, L'\0'}, {0xFDD0, 0x5973, L'\0'}}, /* 女 */
  {{0x2F26, L'\0'}, {0xFDD0, 0x5B50, L'\0'}}, /* 子 */
  {{0x2F27, L'\0'}, {0xFDD0, 0x5B80, L'\0'}}, /* 宀 */
  {{0x2F28, L'\0'}, {0xFDD0, 0x5BF8, L'\0'}}, /* 寸 */
  {{0x2F29, L'\0'}, {0xFDD0, 0x5C0F, L'\0'}}, /* 小 */
  {{0x2F2A, L'\0'}, {0xFDD0, 0x5C22, L'\0'}}, /* 尢 */
  {{0x2F2B, L'\0'}, {0xFDD0, 0x5C38, L'\0'}}, /* 尸 */
  {{0x2F2C, L'\0'}, {0xFDD0, 0x5C6E, L'\0'}}, /* 屮 */
  {{0x2F2D, L'\0'}, {0xFDD0, 0x5C71, L'\0'}}, /* 山 */
  {{0x2F2E, L'\0'}, {0xFDD0, 0x5DDB, L'\0'}}, /* 巛 */
  {{0x2F2F, L'\0'}, {0xFDD0, 0x5DE5, L'\0'}}, /* 工 */
  {{0x2F30, L'\0'}, {0xFDD0, 0x5DF1, L'\0'}}, /* 己 */
  {{0x2F31, L'\0'}, {0xFDD0, 0x5DFE, L'\0'}}, /* 巾 */
  {{0x2F32, L'\0'}, {0xFDD0, 0x5E72, L'\0'}}, /* 干 */
  {{0x2F33, L'\0'}, {0xFDD0, 0x5E7A, L'\0'}}, /* 幺 */
  {{0x2F34, L'\0'}, {0xFDD0, 0x5E7F, L'\0'}}, /* 广 */
  {{0x2F35, L'\0'}, {0xFDD0, 0x5EF4, L'\0'}}, /* 廴 */
  {{0x2F36, L'\0'}, {0xFDD0, 0x5EFE, L'\0'}}, /* 廾 */
  {{0x2F37, L'\0'}, {0xFDD0, 0x5F0B, L'\0'}}, /* 弋 */
  {{0x2F38, L'\0'}, {0xFDD0, 0x5F13, L'\0'}}, /* 弓 */
  {{0x2F39, L'\0'}, {0xFDD0, 0x5F50, L'\0'}}, /* 彐 */
  {{0x2F3A, L'\0'}, {0xFDD0, 0x5F61, L'\0'}}, /* 彡 */
  {{0x2F3B, L'\0'}, {0xFDD0, 0x5F73, L'\0'}}, /* 彳 */
  {{0x2F3C, L'\0'}, {0xFDD0, 0x5FC3, L'\0'}}, /* 心 */
  {{0x2F3D, L'\0'}, {0xFDD0, 0x6208, L'\0'}}, /* 戈 */
  {{0x2F3E, L'\0'}, {0xFDD0, 0x6236, L'\0'}}, /* 戶 */
  {{0x2F3F, L'\0'}, {0xFDD0, 0x624B, L'\0'}}, /* 手 */
  {{0x2F40, L'\0'}, {0xFDD0, 0x652F, L'\0'}}, /* 支 */
  {{0x2F41, L'\0'}, {0xFDD0, 0x6534, L'\0'}}, /* 攴 */
  {{0x2F42, L'\0'}, {0xFDD0, 0x6587, L'\0'}}, /* 文 */
  {{0x2F43, L'\0'}, {0xFDD0, 0x6597, L'\0'}}, /* 斗 */
  {{0x2F44, L'\0'}, {0xFDD0, 0x65A4, L'\0'}}, /* 斤 */
  {{0x2F45, L'\0'}, {0xFDD0, 0x65B9, L'\0'}}, /* 方 */
  {{0x2F46, L'\0'}, {0xFDD0, 0x65E0, L'\0'}}, /* 无 */
  {{0x2F47, L'\0'}, {0xFDD0, 0x65E5, L'\0'}}, /* 日 */
  {{0x2F48, L'\0'}, {0xFDD0, 0x66F0, L'\0'}}, /* 曰 */
  {{0x2F49, L'\0'}, {0xFDD0, 0x6708, L'\0'}}, /* 月 */
  {{0x2F4A, L'\0'}, {0xFDD0, 0x6728, L'\0'}}, /* 木 */
  {{0x2F4B, L'\0'}, {0xFDD0, 0x6B20, L'\0'}}, /* 欠 */
  {{0x2F4C, L'\0'}, {0xFDD0, 0x6B62, L'\0'}}, /* 止 */
  {{0x2F4D, L'\0'}, {0xFDD0, 0x6B79, L'\0'}}, /* 歹 */
  {{0x2F4E, L'\0'}, {0xFDD0, 0x6BB3, L'\0'}}, /* 殳 */
  {{0x2F4F, L'\0'}, {0xFDD0, 0x6BCB, L'\0'}}, /* 毋 */
  {{0x2F50, L'\0'}, {0xFDD0, 0x6BD4, L'\0'}}, /* 比 */
  {{0x2F51, L'\0'}, {0xFDD0, 0x6BDB, L'\0'}}, /* 毛 */
  {{0x2F52, L'\0'}, {0xFDD0, 0x6C0F, L'\0'}}, /* 氏 */
  {{0x2F53, L'\0'}, {0xFDD0, 0x6C14, L'\0'}}, /* 气 */
  {{0x2F54, L'\0'}, {0xFDD0, 0x6C34, L'\0'}}, /* 水 */
  {{0x2F55, L'\0'}, {0xFDD0, 0x706B, L'\0'}}, /* 火 */
  {{0x2F56, L'\0'}, {0xFDD0, 0x722A, L'\0'}}, /* 爪 */
  {{0x2F57, L'\0'}, {0xFDD0, 0x7236, L'\0'}}, /* 父 */
  {{0x2F58, L'\0'}, {0xFDD0, 0x723B, L'\0'}}, /* 爻 */
  {{0x2F59, L'\0'}, {0xFDD0, 0x723F, L'\0'}}, /* 爿 */
  {{0x2F5A, L'\0'}, {0xFDD0, 0x7247, L'\0'}}, /* 片 */
  {{0x2F5B, L'\0'}, {0xFDD0, 0x7259, L'\0'}}, /* 牙 */
  {{0x2F5C, L'\0'}, {0xFDD0, 0x725B, L'\0'}}, /* 牛 */
  {{0x2F5D, L'\0'}, {0xFDD0, 0x72AC, L'\0'}}, /* 犬 */
  {{0x2F5E, L'\0'}, {0xFDD0, 0x7384, L'\0'}}, /* 玄 */
  {{0x2F5F, L'\0'}, {0xFDD0, 0x7389, L'\0'}}, /* 玉 */
  {{0x2F60, L'\0'}, {0xFDD0, 0x74DC, L'\0'}}, /* 瓜 */
  {{0x2F61, L'\0'}, {0xFDD0, 0x74E6, L'\0'}}, /* 瓦 */
  {{0x2F62, L'\0'}, {0xFDD0, 0x7518, L'\0'}}, /* 甘 */
  {{0x2F63, L'\0'}, {0xFDD0, 0x751F, L'\0'}}, /* 生 */
  {{0x2F64, L'\0'}, {0xFDD0, 0x7528, L'\0'}}, /* 用 */
  {{0x2F65, L'\0'}, {0xFDD0, 0x7530, L'\0'}}, /* 田 */
  {{0x2F66, L'\0'}, {0xFDD0, 0x758B, L'\0'}}, /* 疋 */
  {{0x2F67, L'\0'}, {0xFDD0, 0x7592, L'\0'}}, /* 疒 */
  {{0x2F68, L'\0'}, {0xFDD0, 0x7676, L'\0'}}, /* 癶 */
  {{0x2F69, L'\0'}, {0xFDD0, 0x767D, L'\0'}}, /* 白 */
  {{0x2F6A, L'\0'}, {0xFDD0, 0x76AE, L'\0'}}, /* 皮 */
  {{0x2F6B, L'\0'}, {0xFDD0, 0x76BF, L'\0'}}, /* 皿 */
  {{0x2F6C, L'\0'}, {0xFDD0, 0x76EE, L'\0'}}, /* 目 */
  {{0x2F6D, L'\0'}, {0xFDD0, 0x77DB, L'\0'}}, /* 矛 */
  {{0x2F6E, L'\0'}, {0xFDD0, 0x77E2, L'\0'}}, /* 矢 */
  {{0x2F6F, L'\0'}, {0xFDD0, 0x77F3, L'\0'}}, /* 石 */
  {{0x2F70, L'\0'}, {0xFDD0, 0x793A, L'\0'}}, /* 示 */
  {{0x2F71, L'\0'}, {0xFDD0, 0x79B8, L'\0'}}, /* 禸 */
  {{0x2F72, L'\0'}, {0xFDD0, 0x79BE, L'\0'}}, /* 禾 */
  {{0x2F73, L'\0'}, {0xFDD0, 0x7A74, L'\0'}}, /* 穴 */
  {{0x2F74, L'\0'}, {0xFDD0, 0x7ACB, L'\0'}}, /* 立 */
  {{0x2F75, L'\0'}, {0xFDD0, 0x7AF9, L'\0'}}, /* 竹 */
  {{0x2F76, L'\0'}, {0xFDD0, 0x7C73, L'\0'}}, /* 米 */
  {{0x2F77, L'\0'}, {0xFDD0, 0x7CF8, L'\0'}}, /* 糸 */
  {{0x2F78, L'\0'}, {0xFDD0, 0x7F36, L'\0'}}, /* 缶 */
  {{0x2F79, L'\0'}, {0xFDD0, 0x7F51, L'\0'}}, /* 网 */
  {{0x2F7A, L'\0'}, {0xFDD0, 0x7F8A, L'\0'}}, /* 羊 */
  {{0x2F7B, L'\0'}, {0xFDD0, 0x7FBD, L'\0'}}, /* 羽 */
  {{0x2F7C, L'\0'}, {0xFDD0, 0x8001, L'\0'}}, /* 老 */
  {{0x2F7D, L'\0'}, {0xFDD0, 0x800C, L'\0'}}, /* 而 */
  {{0x2F7E, L'\0'}, {0xFDD0, 0x8012, L'\0'}}, /* 耒 */
  {{0x2F7F, L'\0'}, {0xFDD0, 0x8033, L'\0'}}, /* 耳 */
  {{0x2F80, L'\0'}, {0xFDD0, 0x807F, L'\0'}}, /* 聿 */
  {{0x2F81, L'\0'}, {0xFDD0, 0x8089, L'\0'}}, /* 肉 */
  {{0x2F82, L'\0'}, {0xFDD0, 0x81E3, L'\0'}}, /* 臣 */
  {{0x2F83, L'\0'}, {0xFDD0, 0x81EA, L'\0'}}, /* 自 */
  {{0x2F84, L'\0'}, {0xFDD0, 0x81F3, L'\0'}}, /* 至 */
  {{0x2F85, L'\0'}, {0xFDD0, 0x81FC, L'\0'}}, /* 臼 */
  {{0x2F86, L'\0'}, {0xFDD0, 0x820C, L'\0'}}, /* 舌 */
  {{0x2F87, L'\0'}, {0xFDD0, 0x821B, L'\0'}}, /* 舛 */
  {{0x2F88, L'\0'}, {0xFDD0, 0x821F, L'\0'}}, /* 舟 */
  {{0x2F89, L'\0'}, {0xFDD0, 0x826E, L'\0'}}, /* 艮 */
  {{0x2F8A, L'\0'}, {0xFDD0, 0x8272, L'\0'}}, /* 色 */
  {{0x2F8B, L'\0'}, {0xFDD0, 0x8278, L'\0'}}, /* 艸 */
  {{0x2F8C, L'\0'}, {0xFDD0, 0x864D, L'\0'}}, /* 虍 */
  {{0x2F8D, L'\0'}, {0xFDD0, 0x866B, L'\0'}}, /* 虫 */
  {{0x2F8E, L'\0'}, {0xFDD0, 0x8840, L'\0'}}, /* 血 */
  {{0x2F8F, L'\0'}, {0xFDD0, 0x884C, L'\0'}}, /* 行 */
  {{0x2F90, L'\0'}, {0xFDD0, 0x8863, L'\0'}}, /* 衣 */
  {{0x2F91, L'\0'}, {0xFDD0, 0x897E, L'\0'}}, /* 襾 */
  {{0x2F92, L'\0'}, {0xFDD0, 0x898B, L'\0'}}, /* 見 */
  {{0x2F93, L'\0'}, {0xFDD0, 0x89D2, L'\0'}}, /* 角 */
  {{0x2F94, L'\0'}, {0xFDD0, 0x8A00, L'\0'}}, /* 言 */
  {{0x2F95, L'\0'}, {0xFDD0, 0x8C37, L'\0'}}, /* 谷 */
  {{0x2F96, L'\0'}, {0xFDD0, 0x8C46, L'\0'}}, /* 豆 */
  {{0x2F97, L'\0'}, {0xFDD0, 0x8C55, L'\0'}}, /* 豕 */
  {{0x2F98, L'\0'}, {0xFDD0, 0x8C78, L'\0'}}, /* 豸 */
  {{0x2F99, L'\0'}, {0xFDD0, 0x8C9D, L'\0'}}, /* 貝 */
  {{0x2F9A, L'\0'}, {0xFDD0, 0x8D64, L'\0'}}, /* 赤 */
  {{0x2F9B, L'\0'}, {0xFDD0, 0x8D70, L'\0'}}, /* 走 */
  {{0x2F9C, L'\0'}, {0xFDD0, 0x8DB3, L'\0'}}, /* 足 */
  {{0x2F9D, L'\0'}, {0xFDD0, 0x8EAB, L'\0'}}, /* 身 */
  {{0x2F9E, L'\0'}, {0xFDD0, 0x8ECA, L'\0'}}, /* 車 */
  {{0x2F9F, L'\0'}, {0xFDD0, 0x8F9B, L'\0'}}, /* 辛 */
  {{0x2FA0, L'\0'}, {0xFDD0, 0x8FB0, L'\0'}}, /* 辰 */
  {{0x2FA1, L'\0'}, {0xFDD0, 0x8FB5, L'\0'}}, /* 辵 */
  {{0x2FA2, L'\0'}, {0xFDD0, 0x9091, L'\0'}}, /* 邑 */
  {{0x2FA3, L'\0'}, {0xFDD0, 0x9149, L'\0'}}, /* 酉 */
  {{0x2FA4, L'\0'}, {0xFDD0, 0x91C6, L'\0'}}, /* 釆 */
  {{0x2FA5, L'\0'}, {0xFDD0, 0x91CC, L'\0'}}, /* 里 */
  {{0x2FA6, L'\0'}, {0xFDD0, 0x91D1, L'\0'}}, /* 金 */
  {{0x2FA7, L'\0'}, {0xFDD0, 0x9577, L'\0'}}, /* 長 */
  {{0x2FA8, L'\0'}, {0xFDD0, 0x9580, L'\0'}}, /* 門 */
  {{0x2FA9, L'\0'}, {0xFDD0, 0x961C, L'\0'}}, /* 阜 */
  {{0x2FAA, L'\0'}, {0xFDD0, 0x96B6, L'\0'}}, /* 隶 */
  {{0x2FAB, L'\0'}, {0xFDD0, 0x96B9, L'\0'}}, /* 隹 */
  {{0x2FAC, L'\0'}, {0xFDD0, 0x96E8, L'\0'}}, /* 雨 */
  {{0x2FAD, L'\0'}, {0xFDD0, 0x9751, L'\0'}}, /* 靑 */
  {{0x2FAE, L'\0'}, {0xFDD0, 0x975E, L'\0'}}, /* 非 */
  {{0x2FAF, L'\0'}, {0xFDD0, 0x9762, L'\0'}}, /* 面 */
  {{0x2FB0, L'\0'}, {0xFDD0, 0x9769, L'\0'}}, /* 革 */
  {{0x2FB1, L'\0'}, {0xFDD0, 0x97CB, L'\0'}}, /* 韋 */
  {{0x2FB2, L'\0'}, {0xFDD0, 0x97ED, L'\0'}}, /* 韭 */
  {{0x2FB3, L'\0'}, {0xFDD0, 0x97F3, L'\0'}}, /* 音 */
  {{0x2FB4, L'\0'}, {0xFDD0, 0x9801, L'\0'}}, /* 頁 */
  {{0x2FB5, L'\0'}, {0xFDD0, 0x98A8, L'\0'}}, /* 風 */
  {{0x2FB6, L'\0'}, {0xFDD0, 0x98DB, L'\0'}}, /* 飛 */
  {{0x2FB7, L'\0'}, {0xFDD0, 0x98DF, L'\0'}}, /* 食 */
  {{0x2FB8, L'\0'}, {0xFDD0, 0x9996, L'\0'}}, /* 首 */
  {{0x2FB9, L'\0'}, {0xFDD0, 0x9999, L'\0'}}, /* 香 */
  {{0x2FBA, L'\0'}, {0xFDD0, 0x99AC, L'\0'}}, /* 馬 */
  {{0x2FBB, L'\0'}, {0xFDD0, 0x9AA8, L'\0'}}, /* 骨 */
  {{0x2FBC, L'\0'}, {0xFDD0, 0x9AD8, L'\0'}}, /* 高 */
  {{0x2FBD, L'\0'}, {0xFDD0, 0x9ADF, L'\0'}}, /* 髟 */
  {{0x2FBE, L'\0'}, {0xFDD0, 0x9B25, L'\0'}}, /* 鬥 */
  {{0x2FBF, L'\0'}, {0xFDD0, 0x9B2F, L'\0'}}, /* 鬯 */
  {{0x2FC0, L'\0'}, {0xFDD0, 0x9B32, L'\0'}}, /* 鬲 */
  {{0x2FC1, L'\0'}, {0xFDD0, 0x9B3C, L'\0'}}, /* 鬼 */
  {{0x2FC2, L'\0'}, {0xFDD0, 0x9B5A, L'\0'}}, /* 魚 */
  {{0x2FC3, L'\0'}, {0xFDD0, 0x9CE5, L'\0'}}, /* 鳥 */
  {{0x2FC4, L'\0'}, {0xFDD0, 0x9E75, L'\0'}}, /* 鹵 */
  {{0x2FC5, L'\0'}, {0xFDD0, 0x9E7F, L'\0'}}, /* 鹿 */
  {{0x2FC6, L'\0'}, {0xFDD0, 0x9EA5, L'\0'}}, /* 麥 */
  {{0x2FC7, L'\0'}, {0xFDD0, 0x9EBB, L'\0'}}, /* 麻 */
  {{0x2FC8, L'\0'}, {0xFDD0, 0x9EC3, L'\0'}}, /* 黃 */
  {{0x2FC9, L'\0'}, {0xFDD0, 0x9ECD, L'\0'}}, /* 黍 */
  {{0x2FCA, L'\0'}, {0xFDD0, 0x9ED1, L'\0'}}, /* 黑 */
  {{0x2FCB, L'\0'}, {0xFDD0, 0x9EF9, L'\0'}}, /* 黹 */
  {{0x2FCC, L'\0'}, {0xFDD0, 0x9EFD, L'\0'}}, /* 黽 */
  {{0x2FCD, L'\0'}, {0xFDD0, 0x9F0E, L'\0'}}, /* 鼎 */
  {{0x2FCE, L'\0'}, {0xFDD0, 0x9F13, L'\0'}}, /* 鼓 */
  {{0x2FCF, L'\0'}, {0xFDD0, 0x9F20, L'\0'}}, /* 鼠 */
  {{0x2FD0, L'\0'}, {0xFDD0, 0x9F3B, L'\0'}}, /* 鼻 */
  {{0x2FD1, L'\0'}, {0xFDD0, 0x9F4A, L'\0'}}, /* 齊 */
  {{0x2FD2, L'\0'}, {0xFDD0, 0x9F52, L'\0'}}, /* 齒 */
  {{0x2FD3, L'\0'}, {0xFDD0, 0x9F8D, L'\0'}}, /* 龍 */
  {{0x2FD4, L'\0'}, {0xFDD0, 0x9F9C, L'\0'}}, /* 龜 */
  {{0x2FD5, L'\0'}, {0xFDD0, 0x9FA0, L'\0'}}, /* 龠 */
  {0, 0},
};

/*
 Reference:
   cldr - Revision 12061: /trunk/common/collation
   http://unicode.org/repos/cldr/trunk/common/collation/zh.xml
   <collation type='stroke' alt='short'>
   U+FDD0 (Noncharacter) is used.
 */
struct hanzi_index HZ_STROKE[]={
  {{0x4E00, 0x756B, L'\0'}, {0xFDD0, 0x2801, L'\0'}}, /* 一畫 */
  {{0x4E8C, 0x756B, L'\0'}, {0xFDD0, 0x2802, L'\0'}}, /* 二畫 */
  {{0x4E09, 0x756B, L'\0'}, {0xFDD0, 0x2803, L'\0'}}, /* 三畫 */
  {{0x56DB, 0x756B, L'\0'}, {0xFDD0, 0x2804, L'\0'}}, /* 四畫 */
  {{0x4E94, 0x756B, L'\0'}, {0xFDD0, 0x2805, L'\0'}}, /* 五畫 */
  {{0x516D, 0x756B, L'\0'}, {0xFDD0, 0x2806, L'\0'}}, /* 六畫 */
  {{0x4E03, 0x756B, L'\0'}, {0xFDD0, 0x2807, L'\0'}}, /* 七畫 */
  {{0x516B, 0x756B, L'\0'}, {0xFDD0, 0x2808, L'\0'}}, /* 八畫 */
  {{0x4E5D, 0x756B, L'\0'}, {0xFDD0, 0x2809, L'\0'}}, /* 九畫 */
  {{0x5341, 0x756B, L'\0'}, {0xFDD0, 0x280A, L'\0'}}, /* 十畫 */
  {{0x5341, 0x4E00, 0x756B, L'\0'}, {0xFDD0, 0x280B, L'\0'}}, /* 十一畫 */
  {{0x5341, 0x4E8C, 0x756B, L'\0'}, {0xFDD0, 0x280C, L'\0'}}, /* 十二畫 */
  {{0x5341, 0x4E09, 0x756B, L'\0'}, {0xFDD0, 0x280D, L'\0'}}, /* 十三畫 */
  {{0x5341, 0x56DB, 0x756B, L'\0'}, {0xFDD0, 0x280E, L'\0'}}, /* 十四畫 */
  {{0x5341, 0x4E94, 0x756B, L'\0'}, {0xFDD0, 0x280F, L'\0'}}, /* 十五畫 */
  {{0x5341, 0x516D, 0x756B, L'\0'}, {0xFDD0, 0x2810, L'\0'}}, /* 十六畫 */
  {{0x5341, 0x4E03, 0x756B, L'\0'}, {0xFDD0, 0x2811, L'\0'}}, /* 十七畫 */
  {{0x5341, 0x516B, 0x756B, L'\0'}, {0xFDD0, 0x2812, L'\0'}}, /* 十八畫 */
  {{0x5341, 0x4E5D, 0x756B, L'\0'}, {0xFDD0, 0x2813, L'\0'}}, /* 十九畫 */
  {{0x4E8C, 0x5341, 0x756B, L'\0'}, {0xFDD0, 0x2814, L'\0'}}, /* 二十畫 */
  {{0x4E8C, 0x5341, 0x4E00, 0x756B, L'\0'}, {0xFDD0, 0x2815, L'\0'}}, /* 二十一畫 */
  {{0x4E8C, 0x5341, 0x4E8C, 0x756B, L'\0'}, {0xFDD0, 0x2816, L'\0'}}, /* 二十二畫 */
  {{0x4E8C, 0x5341, 0x4E09, 0x756B, L'\0'}, {0xFDD0, 0x2817, L'\0'}}, /* 二十三畫 */
  {{0x4E8C, 0x5341, 0x56DB, 0x756B, L'\0'}, {0xFDD0, 0x2818, L'\0'}}, /* 二十四畫 */
  {{0x4E8C, 0x5341, 0x4E94, 0x756B, L'\0'}, {0xFDD0, 0x2819, L'\0'}}, /* 二十五畫 */
  {{0x4E8C, 0x5341, 0x516D, 0x756B, L'\0'}, {0xFDD0, 0x281A, L'\0'}}, /* 二十六畫 */
  {{0x4E8C, 0x5341, 0x4E03, 0x756B, L'\0'}, {0xFDD0, 0x281B, L'\0'}}, /* 二十七畫 */
  {{0x4E8C, 0x5341, 0x516B, 0x756B, L'\0'}, {0xFDD0, 0x281C, L'\0'}}, /* 二十八畫 */
  {{0x4E8C, 0x5341, 0x4E5D, 0x756B, L'\0'}, {0xFDD0, 0x281D, L'\0'}}, /* 二十九畫 */
  {{0x4E09, 0x5341, 0x756B, L'\0'},         {0xFDD0, 0x281E, L'\0'}}, /* 三十畫 */
  {{0x4E09, 0x5341, 0x4E00, 0x756B, L'\0'}, {0xFDD0, 0x281F, L'\0'}}, /* 三十一畫 */
  {{0x4E09, 0x5341, 0x4E8C, 0x756B, L'\0'}, {0xFDD0, 0x2820, L'\0'}}, /* 三十二畫 */
  {{0x4E09, 0x5341, 0x4E09, 0x756B, L'\0'}, {0xFDD0, 0x2821, L'\0'}}, /* 三十三畫 */
  //  {{0x4E09, 0x5341, 0x56DB, 0x756B, L'\0'}, {0xFDD0, 0x2822, L'\0'}}, /* 三十四畫 */
  {{0x4E09, 0x5341, 0x4E94, 0x756B, L'\0'}, {0xFDD0, 0x2823, L'\0'}}, /* 三十五畫 */
  {{0x4E09, 0x5341, 0x516D, 0x756B, L'\0'}, {0xFDD0, 0x2824, L'\0'}}, /* 三十六畫 */
  //  {{0x4E09, 0x5341, 0x4E03, 0x756B, L'\0'}, {0xFDD0, 0x2825, L'\0'}}, /* 三十七畫 */
  //  {{0x4E09, 0x5341, 0x516B, 0x756B, L'\0'}, {0xFDD0, 0x2826, L'\0'}}, /* 三十八畫 */
  {{0x4E09, 0x5341, 0x4E5D, 0x756B, L'\0'}, {0xFDD0, 0x2827, L'\0'}}, /* 三十九畫 */
  {{0x56DB, 0x5341, 0x516B, 0x756B, L'\0'}, {0xFDD0, 0x2830, L'\0'}}, /* 四十八畫 */
  {0, 0},
};

/*
 Reference:
   cldr - Revision 12061: /trunk/common/collation
   http://unicode.org/repos/cldr/trunk/common/collation/zh.xml
   <collation type='pinyin'>
   U+FDD0 (Noncharacter) is used.
 */
struct hanzi_index HZ_PINYIN[]={
  {{L'A', L'\0'}, {0xFDD0, L'A', L'\0'}}, /* A */
  {{L'B', L'\0'}, {0xFDD0, L'B', L'\0'}}, /* B */
  {{L'C', L'\0'}, {0xFDD0, L'C', L'\0'}}, /* C */
  {{L'D', L'\0'}, {0xFDD0, L'D', L'\0'}}, /* D */
  {{L'E', L'\0'}, {0xFDD0, L'E', L'\0'}}, /* E */
  {{L'F', L'\0'}, {0xFDD0, L'F', L'\0'}}, /* F */
  {{L'G', L'\0'}, {0xFDD0, L'G', L'\0'}}, /* G */
  {{L'H', L'\0'}, {0xFDD0, L'H', L'\0'}}, /* H */
  {{L'J', L'\0'}, {0xFDD0, L'J', L'\0'}}, /* J */
  {{L'K', L'\0'}, {0xFDD0, L'K', L'\0'}}, /* K */
  {{L'L', L'\0'}, {0xFDD0, L'L', L'\0'}}, /* L */
  {{L'M', L'\0'}, {0xFDD0, L'M', L'\0'}}, /* M */
  {{L'N', L'\0'}, {0xFDD0, L'N', L'\0'}}, /* N */
  {{L'O', L'\0'}, {0xFDD0, L'O', L'\0'}}, /* O */
  {{L'P', L'\0'}, {0xFDD0, L'P', L'\0'}}, /* P */
  {{L'Q', L'\0'}, {0xFDD0, L'Q', L'\0'}}, /* Q */
  {{L'R', L'\0'}, {0xFDD0, L'R', L'\0'}}, /* R */
  {{L'S', L'\0'}, {0xFDD0, L'S', L'\0'}}, /* S */
  {{L'T', L'\0'}, {0xFDD0, L'T', L'\0'}}, /* T */
  {{L'W', L'\0'}, {0xFDD0, L'W', L'\0'}}, /* W */
  {{L'X', L'\0'}, {0xFDD0, L'X', L'\0'}}, /* X */
  {{L'Y', L'\0'}, {0xFDD0, L'Y', L'\0'}}, /* Y */
  {{L'Z', L'\0'}, {0xFDD0, L'Z', L'\0'}}, /* Z */
  {0, 0},
};

/*
 Reference:
   cldr - Revision 12061: /trunk/common/collation
   http://unicode.org/repos/cldr/trunk/common/collation/zh.xml
   <collation type='zhuyin'>
   U+FDD0 (Noncharacter) is used.
 */
struct hanzi_index HZ_ZHUYIN[]={
  {{0x3105, L'\0'}, {0xFDD0, 0x3105, L'\0'}}, /* ㄅ */
  {{0x3106, L'\0'}, {0xFDD0, 0x3106, L'\0'}}, /* ㄆ */
  {{0x3107, L'\0'}, {0xFDD0, 0x3107, L'\0'}}, /* ㄇ */
  {{0x3108, L'\0'}, {0xFDD0, 0x3108, L'\0'}}, /* ㄈ */
  {{0x3109, L'\0'}, {0xFDD0, 0x3109, L'\0'}}, /* ㄉ */
  {{0x310A, L'\0'}, {0xFDD0, 0x310A, L'\0'}}, /* ㄊ */
  {{0x310B, L'\0'}, {0xFDD0, 0x310B, L'\0'}}, /* ㄋ */
  {{0x310C, L'\0'}, {0xFDD0, 0x310C, L'\0'}}, /* ㄌ */
  {{0x310D, L'\0'}, {0xFDD0, 0x310D, L'\0'}}, /* ㄍ */
  {{0x310E, L'\0'}, {0xFDD0, 0x310E, L'\0'}}, /* ㄎ */
  {{0x310F, L'\0'}, {0xFDD0, 0x310F, L'\0'}}, /* ㄏ */
  {{0x3110, L'\0'}, {0xFDD0, 0x3110, L'\0'}}, /* ㄐ */
  {{0x3111, L'\0'}, {0xFDD0, 0x3111, L'\0'}}, /* ㄑ */
  {{0x3112, L'\0'}, {0xFDD0, 0x3112, L'\0'}}, /* ㄒ */
  {{0x3113, L'\0'}, {0xFDD0, 0x3113, L'\0'}}, /* ㄓ */
  {{0x3114, L'\0'}, {0xFDD0, 0x3114, L'\0'}}, /* ㄔ */
  {{0x3115, L'\0'}, {0xFDD0, 0x3115, L'\0'}}, /* ㄕ */
  {{0x3116, L'\0'}, {0xFDD0, 0x3116, L'\0'}}, /* ㄖ */
  {{0x3117, L'\0'}, {0xFDD0, 0x3117, L'\0'}}, /* ㄗ */
  {{0x3118, L'\0'}, {0xFDD0, 0x3118, L'\0'}}, /* ㄘ */
  {{0x3119, L'\0'}, {0xFDD0, 0x3119, L'\0'}}, /* ㄙ */
  {{0x311A, L'\0'}, {0xFDD0, 0x311A, L'\0'}}, /* ㄚ */
  {{0x311B, L'\0'}, {0xFDD0, 0x311B, L'\0'}}, /* ㄛ */
  {{0x311C, L'\0'}, {0xFDD0, 0x311C, L'\0'}}, /* ㄜ */
  //  {{0x311D, L'\0'}, {0xFDD0, 0x311D, L'\0'}}, /* ㄝ */
  {{0x311E, L'\0'}, {0xFDD0, 0x311E, L'\0'}}, /* ㄞ */
  {{0x311F, L'\0'}, {0xFDD0, 0x311F, L'\0'}}, /* ㄟ */
  {{0x3120, L'\0'}, {0xFDD0, 0x3120, L'\0'}}, /* ㄠ */
  {{0x3121, L'\0'}, {0xFDD0, 0x3121, L'\0'}}, /* ㄡ */
  {{0x3122, L'\0'}, {0xFDD0, 0x3122, L'\0'}}, /* ㄢ */
  {{0x3123, L'\0'}, {0xFDD0, 0x3123, L'\0'}}, /* ㄣ */
  {{0x3124, L'\0'}, {0xFDD0, 0x3124, L'\0'}}, /* ㄤ */
  {{0x3125, L'\0'}, {0xFDD0, 0x3125, L'\0'}}, /* ㄥ */
  {{0x3126, L'\0'}, {0xFDD0, 0x3126, L'\0'}}, /* ㄦ */
  {{0x3127, L'\0'}, {0xFDD0, 0x3127, L'\0'}}, /* ㄧ */
  {{0x3128, L'\0'}, {0xFDD0, 0x3128, L'\0'}}, /* ㄨ */
  {{0x3129, L'\0'}, {0xFDD0, 0x3129, L'\0'}}, /* ㄩ */
  {0, 0},
};

struct hanzi_index HZ_UNKNOWN[]={
  {{0x6F22, 0x5B57, L'\0'}, {L'\0'}}, /* 漢字 */
  {0, 0},
};
