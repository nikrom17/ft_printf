create_j_table jump_table[23] =
{
	//handle_space,         /* for ' ' */
	handle_percent,       /* for '%' */
	//handle_plus,          /* for '+' */
	//handle_minus,         /* for '-' */
	//handle_hash,          /* for '#' */
	//handle_zero,          /* for '0' */
	//handle_backslash,     /* for '\'' */
	//handle_asterisk,      /* for '*' */
	//handle_width,         /* for '1'...'9' */
	//handle_precision,     /* for '.' */
	//handle_half,          /* for 'h' */
	//handle_long,          /* for 'l' */
	//handle_longlog,       /* for 'L', 'q' */
	//handle_mod_size_t,    /* for 'z', 'Z' */
	handle_integer,       /* for 'd', 'i' */
	//handle_unsigned,      /* for 'u' */
	//handle_octal,         /* for 'o' */
	//handle_hexa,          /* for 'X', 'x' */
	//handle_float,         /* for 'E', 'e', 'F', 'f', 'G', 'g' */
	//handle_character,     /* for 'c' */
	handle_string        /* for 's', 'S' */
	//handle_pointer,       /* for 'p' */
	//handle_wcharacter,    /* for 'C' */
 };

static const uint8_t jump_table[] =
 {
   /* ' ' */  1,            0,            0, /* '#' */  4,
              0, /* '%' */ 14,            0, /* '\''*/  6,
              0,            0, /* '*' */  7, /* '+' */  2,
              0, /* '-' */  3, /* '.' */  9,            0,
   /* '0' */  5, /* '1' */  8, /* '2' */  8, /* '3' */  8,
   /* '4' */  8, /* '5' */  8, /* '6' */  8, /* '7' */  8,
   /* '8' */  8, /* '9' */  8,            0,            0,
              0,            0,            0,            0,
              0, /* 'A' */ 26,            0, /* 'C' */ 25,
              0, /* 'E' */ 19, /* F */   19, /* 'G' */ 19,
              0, /* 'I' */ 29,            0,            0,
   /* 'L' */ 12,            0,            0,            0,
              0,            0,            0, /* 'S' */ 21,
              0,            0,            0,            0,
   /* 'X' */ 18,            0, /* 'Z' */ 13,            0,
              0,            0,            0,            0,
              0, /* 'a' */ 26,            0, /* 'c' */ 20,
   /* 'd' */ 15, /* 'e' */ 19, /* 'f' */ 19, /* 'g' */ 19,
   /* 'h' */ 10, /* 'i' */ 15, /* 'j' */ 28,            0,
   /* 'l' */ 11, /* 'm' */ 24, /* 'n' */ 23, /* 'o' */ 17,
   /* 'p' */ 22, /* 'q' */ 12,            0, /* 's' */ 21,
   /* 't' */ 27, /* 'u' */ 16,            0,            0,
   /* 'x' */ 18,            0, /* 'z' */ 13
 };
