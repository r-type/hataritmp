#ifndef VKBD_DEF_H
#define VKBD_DEF_H 1

typedef struct {
	char norml[NLETT];
	char shift[NLETT];
	int val;	
} Mvk;

Mvk MVk[NPLGN*NLIGN*2]={

//PAGE1

	{ "PG2" ,"PG2"  ,-2}, //0
	{ " F1" ," F1"  ,0x3B},
	{ " F2" ," F2"  ,0x3C},
	{ " F3" ," F3"  ,0x3D},
	{ " F4" ," F4"  ,0x3E},
	{ " F5" ," F5"  ,0x3F},
	{ " F6" ," F6"  ,0x40},
	{ " F7" ," F7"  ,0x41},
	{ " F8" ," F8"  ,0x42},
	{ " F9" ," F9"  ,0x43},
	{ "F10" ,"F10"  ,0x44},
	{ "   " ,"   " ,-1 },
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "   ,-1},
	{ "   " ,"   "   ,-1},

	{ "Esc","Esc" ,0x1}, //20
	{ " 1 "," ! " ,0x2 },
	{ " 2 " ," @ "  ,0x3},
	{ " 3 " ," # "  ,0x4},
	{ " 4 " ," $ "  ,0x5},
	{ " 5 " ," % "  ,0x6},
	{ " 6 " ," ^ "  ,0x7},
	{ " 7 " ," & "  ,0x8},
	{ " 8 "," * "   ,0x9},
	{ " 9 "," ( "   ,0xa},
	{ " 0 "," ) " ,0xb},
	{ " - " ," _ " ,0xc },
	{ " = " ," + "  ,0xd},
	{ " ` " ," ~ "  ,0x29},
	{ "<--" ,"<--"  ,0xe},
	{ "   " ,"   "  ,-1},
	{ "hlp" ,"hlp"  ,0x62},
	{ "   " ,"   "  ,-1},
	{ "udo" ,"udo"   ,0x61},
	{ "   " ,"   "   ,-1},

	{ "tab","tab" ,0xf}, //40
	{ " q "," Q " ,0x10 },
	{ " w " ," W "  ,0x11},
	{ " e " ," E "  ,0x12},
	{ " r " ," R "  ,0x13},
	{ " t " ," T "  ,0x14},
	{ " y " ," Y "  ,0x15},
	{ " u " ," U "  ,0x16},
	{ " i "," I "   ,0x17},
	{ " o "," O "   ,0x18},
	{ " p "," P " ,0x19},
	{ " [ " ," } " ,0x1a },
	{ " ] " ," { "  ,0x1b},
	{ "ret" ,"ret"  ,0x29},
	{ "del" ,"del"  ,0x53},
	{ "   " ,"   "  ,-1},
	{ "ins" ,"ins"  ,0x52},
	{ " \x01 " ," \x01 "  ,0x48},
	{ "Hom" ,"Hom"   ,0x47},
	{ "   " ,"   "   ,-1},


	{ "ctr","ctr" ,0x1D}, //60
	{ " a "," A " ,0x1e },
	{ " s " ," S "  ,0x1f},
	{ " d " ," D "  ,0x20},
	{ " f " ," F "  ,0x21},
	{ " g " ," G "  ,0x22},
	{ " h " ," H "  ,0x23},
	{ " j " ," J "  ,0x24},
	{ " k "," K "   ,0x25},
	{ " l "," L "   ,0x26},
	{ " ; "," : " ,0x27},
	{ " ' " ," \" " ,0x28 },
	{ "RET" ,"RET"  ,0x29},
	{ "URN" ,"URN"  ,0x29},
	{ " \\ " ," | "  ,0x2b},
	{ "   "  ,"   " ,-1},
	{ " \x04 " ," \x04 "  ,0x4b},
	{ " \x02 " ," \x02 "  ,0x50},
	{ " \x03 " ," \x03 "   ,0x4d},
	{ "   " ,"   "   ,-1},


	{ "Lsh","Lsh" ,0x2a}, //80
	{ " z "," Z " ,0x2c },
	{ " x " ," X "  ,0x2d},
	{ " c " ," C "  ,0x2e},
	{ " v " ," V "  ,0x2f},
	{ " b " ," B "  ,0x30},
	{ " n " ," N "  ,0x31},
	{ " m " ," M "  ,0x32},
	{ " , "," K "   ,0x33},
	{ " . "," L "   ,0x34},
	{ " / "," : " ,0x35},
	{ "Rsh" ,"Rsh" ,0x36 },
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "alt" ,"alt"  ,0x38},
	{ "  S" ,"  S"  ,0x39},
	{ "PAC" ,"PAC"  ,0x39},
	{ "E  " ,"E  "  ,0x3a},
	{ "   " ,"   "   ,-1},

// PAGE 2


	{ "PG2" ,"PG2"  ,-2}, //0
	{ " F1" ," F1"  ,0x3B},
	{ " F2" ," F2"  ,0x3C},
	{ " F3" ," F3"  ,0x3D},
	{ " F4" ," F4"  ,0x3E},
	{ " F5" ," F5"  ,0x3F},
	{ " F6" ," F6"  ,0x40},
	{ " F7" ," F7"  ,0x41},
	{ " F8" ," F8"  ,0x42},
	{ " F9" ," F9"  ,0x43},
	{ "F10" ,"F10"  ,0x44},
	{ "   " ,"   " ,-1 },
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "   ,-1},
	{ "   " ,"   "   ,-1},

	{ "Esc","Esc" ,0x1}, //20
	{ " 1 "," ! " ,0x2 },
	{ " 2 " ," @ "  ,0x3},
	{ " 3 " ," # "  ,0x4},
	{ " 4 " ," $ "  ,0x5},
	{ " 5 " ," % "  ,0x6},
	{ " 6 " ," ^ "  ,0x7},
	{ " 7 " ," & "  ,0x8},
	{ " 8 "," * "   ,0x9},
	{ " 9 "," ( "   ,0xa},
	{ " 0 "," ) " ,0xb},
	{ " - " ," _ " ,0xc },
	{ " = " ," + "  ,0xd},
	{ " ` " ," ~ "  ,0x29},
	{ "<--" ,"<--"  ,0xe},
	{ "   " ,"   "  ,-1},
	{ "hlp" ,"hlp"  ,0x62},
	{ "   " ,"   "  ,-1},
	{ "udo" ,"udo"   ,0x61},
	{ "   " ,"   "   ,-1},

	{ "tab","tab" ,0xf}, //40
	{ " q "," Q " ,0x10 },
	{ " w " ," W "  ,0x11},
	{ " e " ," E "  ,0x12},
	{ " r " ," R "  ,0x13},
	{ " t " ," T "  ,0x14},
	{ " y " ," Y "  ,0x15},
	{ " u " ," U "  ,0x16},
	{ " i "," I "   ,0x17},
	{ " o "," O "   ,0x18},
	{ " p "," P " ,0x19},
	{ " [ " ," } " ,0x1a },
	{ " ] " ," { "  ,0x1b},
	{ "ret" ,"ret"  ,0x29},
	{ "del" ,"del"  ,0x53},
	{ "   " ,"   "  ,-1},
	{ "ins" ,"ins"  ,0x52},
	{ " \x01 " ," \x01 "  ,0x48},
	{ "Hom" ,"Hom"   ,0x47},
	{ "   " ,"   "   ,-1},


	{ "ctr","ctr" ,0x1D}, //60
	{ " a "," A " ,0x1e },
	{ " s " ," S "  ,0x1f},
	{ " d " ," D "  ,0x20},
	{ " f " ," F "  ,0x21},
	{ " g " ," G "  ,0x22},
	{ " h " ," H "  ,0x23},
	{ " j " ," J "  ,0x24},
	{ " k "," K "   ,0x25},
	{ " l "," L "   ,0x26},
	{ " ; "," : " ,0x27},
	{ " ' " ," \" " ,0x28 },
	{ "RET" ,"RET"  ,0x29},
	{ "URN" ,"URN"  ,0x29},
	{ " \\ " ," | "  ,0x2b},
	{ "   "  ,"   " ,-1},
	{ " \x04 " ," \x04 "  ,0x4b},
	{ " \x02 " ," \x02 "  ,0x50},
	{ " \x03 " ," \x03 "   ,0x4d},
	{ "   " ,"   "   ,-1},


	{ "Lsh","Lsh" ,0x2a}, //80
	{ " z "," Z " ,0x2c },
	{ " x " ," X "  ,0x2d},
	{ " c " ," C "  ,0x2e},
	{ " v " ," V "  ,0x2f},
	{ " b " ," B "  ,0x30},
	{ " n " ," N "  ,0x31},
	{ " m " ," M "  ,0x32},
	{ " , "," K "   ,0x33},
	{ " . "," L "   ,0x34},
	{ " / "," : " ,0x35},
	{ "Rsh" ,"Rsh" ,0x36 },
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "   " ,"   "  ,-1},
	{ "alt" ,"alt"  ,0x38},
	{ "  S" ,"  S"  ,0x39},
	{ "PAC" ,"PAC"  ,0x39},
	{ "E  " ,"E  "  ,0x3a},
	{ "   " ,"   "   ,-1},

} ;

#endif
