#include "exkana.h"

UChar AKASATANA[]={
	0x3042, /* あ */
	0x304b, /* か */
	0x3055, /* さ */
	0x305f, /* た */
	0x306a, /* な */
	0x306f, /* は */
	0x307e, /* ま */
	0x3084, /* や */
	0x3089, /* ら */
	0x308f, /* わ */
	0
};
char AKASATANAutf8[]={
	0xe3,0x81,0x82, /* あ */
	0xe3,0x81,0x8b, /* か */
	0xe3,0x81,0x95, /* さ */
	0xe3,0x81,0x9f, /* た */
	0xe3,0x81,0xaa, /* な */
	0xe3,0x81,0xaf, /* は */
	0xe3,0x81,0xbe, /* ま */
	0xe3,0x82,0x84, /* や */
	0xe3,0x82,0x89, /* ら */
	0xe3,0x82,0x8f, /* わ */
	0
};
UChar *akasatana;

UChar AIUEO[]={
	0x3042, /* あ */
	0x3044, /* い */
	0x3046, /* う */
	0x3048, /* え */
	0x304a, /* お */
	0x304b, /* か */
	0x304d, /* き */
	0x304f, /* く */
	0x3051, /* け */
	0x3053, /* こ */
	0x3055, /* さ */
	0x3057, /* し */
	0x3059, /* す */
	0x305b, /* せ */
	0x305d, /* そ */
	0x305f, /* た */
	0x3061, /* ち */
	0x3064, /* つ */
	0x3066, /* て */
	0x3068, /* と */
	0x306a, /* な */
	0x306b, /* に */
	0x306c, /* ぬ */
	0x306d, /* ね */
	0x306e, /* の */
	0x306f, /* は */
	0x3072, /* ひ */
	0x3075, /* ふ */
	0x3078, /* へ */
	0x307b, /* ほ */
	0x307e, /* ま */
	0x307f, /* み */
	0x3080, /* む */
	0x3081, /* め */
	0x3082, /* も */
	0x3084, /* や */
	0x3086, /* ゆ */
	0x3088, /* よ */
	0x3089, /* ら */
	0x308a, /* り */
	0x308b, /* る */
	0x308c, /* れ */
	0x308d, /* ろ */
	0x308f, /* わ */
	0x3090, /* ゐ */
	0x3091, /* ゑ */
	0x3092, /* を */
	0x3093, /* ん */
	0
};
UChar *aiueo;
UChar kanatable[]={
	0x3042, /* あ */
	0x3042, /* あ */
	0x3044, /* い */
	0x3044, /* い */
	0x3046, /* う */
	0x3046, /* う */
	0x3048, /* え */
	0x3048, /* え */
	0x304a, /* お */
	0x304a, /* お */
	0x304b, /* か */
	0x304b, /* か */
	0x304d, /* き */
	0x304d, /* き */
	0x304f, /* く */
	0x304f, /* く */
	0x3051, /* け */
	0x3051, /* け */
	0x3053, /* こ */
	0x3053, /* こ */
	0x3055, /* さ */
	0x3055, /* さ */
	0x3057, /* し */
	0x3057, /* し */
	0x3059, /* す */
	0x3059, /* す */
	0x305b, /* せ */
	0x305b, /* せ */
	0x305d, /* そ */
	0x305d, /* そ */
	0x305f, /* た */
	0x305f, /* た */
	0x3061, /* ち */
	0x3061, /* ち */
	0x3064, /* つ */
	0x3064, /* つ */
	0x3064, /* つ */
	0x3066, /* て */
	0x3066, /* て */
	0x3068, /* と */
	0x3068, /* と */
	0x306a, /* な */
	0x306b, /* に */
	0x306c, /* ぬ */
	0x306d, /* ね */
	0x306e, /* の */
	0x306f, /* は */
	0x306f, /* は */
	0x306f, /* は */
	0x3072, /* ひ */
	0x3072, /* ひ */
	0x3072, /* ひ */
	0x3075, /* ふ */
	0x3075, /* ふ */
	0x3075, /* ふ */
	0x3078, /* へ */
	0x3078, /* へ */
	0x3078, /* へ */
	0x307b, /* ほ */
	0x307b, /* ほ */
	0x307b, /* ほ */
	0x307e, /* ま */
	0x307f, /* み */
	0x3080, /* む */
	0x3081, /* め */
	0x3082, /* も */
	0x3084, /* や */
	0x3084, /* や */
	0x3086, /* ゆ */
	0x3086, /* ゆ */
	0x3088, /* よ */
	0x3088, /* よ */
	0x3089, /* ら */
	0x308a, /* り */
	0x308b, /* る */
	0x308c, /* れ */
	0x308d, /* ろ */
	0x308f, /* わ */
	0x308f, /* わ */
	0x3090, /* ゐ */
	0x3091, /* ゑ */
	0x3092, /* を */
	0x3093, /* ん */
	0x3046, /* う */
	0x304b, /* か */
	0x3051, /* け */
	0x308f, /* わ */
	0x3090, /* ゐ */
	0x3091, /* ゑ */
	0x3092, /* を */
	0
};
UChar extkanatable[]={
	0x304f, /* く */
	0x3057, /* し */
	0x3059, /* す */
	0x3068, /* と */
	0x306c, /* ぬ */
	0x306f, /* は */
	0x3072, /* ひ */
	0x3075, /* ふ */
	0x3078, /* へ */
	0x307b, /* ほ */
	0x3080, /* む */
	0x3089, /* ら */
	0x308a, /* り */
	0x308b, /* る */
	0x308c, /* れ */
	0x308d, /* ろ */
	0
};
UChar circkanatable[]={
	0x3042, /* あ */
	0x3044, /* い */
	0x3046, /* う */
	0x3048, /* え */
	0x304a, /* お */
	0x304b, /* か */
	0x304d, /* き */
	0x304f, /* く */
	0x3051, /* け */
	0x3053, /* こ */
	0x3055, /* さ */
	0x3057, /* し */
	0x3059, /* す */
	0x305b, /* せ */
	0x305d, /* そ */
	0x305f, /* た */
	0x3061, /* ち */
	0x3064, /* つ */
	0x3066, /* て */
	0x3068, /* と */
	0x306a, /* な */
	0x306b, /* に */
	0x306c, /* ぬ */
	0x306d, /* ね */
	0x306e, /* の */
	0x306f, /* は */
	0x3072, /* ひ */
	0x3075, /* ふ */
	0x3078, /* へ */
	0x307b, /* ほ */
	0x307e, /* ま */
	0x307f, /* み */
	0x3080, /* む */
	0x3081, /* め */
	0x3082, /* も */
	0x3084, /* や */
	0x3086, /* ゆ */
	0x3088, /* よ */
	0x3089, /* ら */
	0x308a, /* り */
	0x308b, /* る */
	0x308c, /* れ */
	0x308d, /* ろ */
	0x308f, /* わ */
	0x3090, /* ゐ */
	0x3091, /* ゑ */
	0x3092, /* を */
	0
};


UChar GANADA[]={
	0x3131, /* ㄱ (Hangul Compatibility Jamo) */
	0x3134, /* ㄴ */
	0x3137, /* ㄷ */
	0x3139, /* ㄹ */
	0x3141, /* ㅁ */
	0x3142, /* ㅂ */
	0x3145, /* ㅅ */
	0x3147, /* ㅇ */
	0x3148, /* ㅈ */
	0x314A, /* ㅊ */
	0x314B, /* ㅋ */
	0x314C, /* ㅌ */
	0x314D, /* ㅍ */
	0x314E, /* ㅎ */
	0
};


UChar DVNG_HEAD[]={
	/* Independent vowels */
	0x0904, /* ऄ */
	0x0905, /* अ */
	0x0906, /* आ */
	0x0907, /* इ */
	0x0908, /* ई */
	0x0909, /* उ */
	0x090A, /* ऊ */
	0x090B, /* ऋ */
	0x090C, /* ज */
	0x090D, /* झ */
	0x090E, /* ञ */
	0x090F, /* ए */
	0x0910, /* ऐ */
	0x0911, /* ऑ */
	0x0912, /* ऒ */
	0x0913, /* ओ */
	0x0914, /* औ */
	/* Consonants */
	0x0915, /* क */
	0x0916, /* ख */
	0x0917, /* ग */
	0x0918, /* घ */
	0x0919, /* ङ */
	0x091A, /* च */
	0x091B, /* छ */
	0x091C, /* ज */
	0x091D, /* झ */
	0x091E, /* ञ */
	0x091F, /* ट */
	0x0920, /* ठ */
	0x0921, /* ड */
	0x0922, /* ढ */
	0x0923, /* ण */
	0x0924, /* त */
	0x0925, /* थ */
	0x0926, /* द */
	0x0927, /* ध */
	0x0928, /* न */
	0x092A, /* प */
	0x092B, /* फ */
	0x092C, /* ब */
	0x092D, /* भ */
	0x092E, /* म */
	0x092F, /* य */
	0x0930, /* र */
	0x0932, /* ल */
	0x0933, /* ळ */
	0x0935, /* व */
	0x0936, /* श */
	0x0937, /* ष */
	0x0938, /* स */
	0x0939, /* ह */
	0
};


UChar THAI_HEAD[]={
	0x0E01, /* ก */
	0x0E02, /* ข */
	0x0E03, /* ฃ */
	0x0E04, /* ค */
	0x0E05, /* ฅ */
	0x0E06, /* ฆ */
	0x0E07, /* ง */
	0x0E08, /* จ */
	0x0E09, /* ฉ */
	0x0E0A, /* ช */
	0x0E0B, /* ซ */
	0x0E0C, /* ฌ */
	0x0E0D, /* ญ */
	0x0E0E, /* ฎ */
	0x0E0F, /* ฏ */
	0x0E10, /* ฐ */
	0x0E11, /* ฑ */
	0x0E12, /* ฒ */
	0x0E13, /* ณ */
	0x0E14, /* ด */
	0x0E15, /* ต */
	0x0E16, /* ถ */
	0x0E17, /* ท */
	0x0E18, /* ธ */
	0x0E19, /* น */
	0x0E1A, /* บ */
	0x0E1B, /* ป */
	0x0E1C, /* ผ */
	0x0E1D, /* ฝ */
	0x0E1E, /* พ */
	0x0E1F, /* ฟ */
	0x0E20, /* ภ */
	0x0E21, /* ม */
	0x0E22, /* ย */
	0x0E23, /* ร */
	0x0E24, /* ฤ */
	0x0E25, /* ล */
	0x0E26, /* ฦ */
	0x0E27, /* ว */
	0x0E28, /* ศ */
	0x0E29, /* ษ */
	0x0E2A, /* ส */
	0x0E2B, /* ห */
	0x0E2C, /* ฬ */
	0x0E2D, /* อ */
	0x0E2E, /* ฮ */
	0
};
