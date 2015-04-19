#include "Arduino.h",


#define CTRL_C1_EN                       0
#define CTRL_C1_VOL                      1
#define CTRL_C1_PAN                      2
#define CTRL_C1_PATCH                    3
#define CTRL_C1_REV_SEND                 4
#define CTRL_C1_CHO_SEND                 5
#define CTRL_C1_FT                       6
#define CTRL_C1_VIB_RATE                 7
#define CTRL_C1_VIB_DEPTH                8
#define CTRL_C1_VIB_DELAY                9
#define CTRL_C1_FILTER_CUTOFF            10
#define CTRL_C1_FILTER_RES               11
#define CTRL_C1_ENV_ATTACK               12
#define CTRL_C1_ENV_DECAY                13
#define CTRL_C1_ENV_RELEASE              14
#define CTRL_C1_MOD_BEND_PITCH           15
#define CTRL_C1_MOD_BEND_FILTER          16
#define CTRL_C1_MOD_BEND_AMP             17
#define CTRL_C1_MOD_BEND_LFO_PITCH       18
#define CTRL_C1_MOD_BEND_LFO_FILTER      19
#define CTRL_C1_MOD_BEND_LFO_AMP         20
#define CTRL_C1_MOD_WHEEL_PITCH          21
#define CTRL_C1_MOD_WHEEL_FILTER         22
#define CTRL_C1_MOD_WHEEL_AMP            23
#define CTRL_C1_MOD_WHEEL_LFO_PITCH      24
#define CTRL_C1_MOD_WHEEL_LFO_FILTER     25
#define CTRL_C1_MOD_WHEEL_LFO_AMP        26
#define CTRL_C1_MOD_CC1_PITCH            27
#define CTRL_C1_MOD_CC1_FILTER           28
#define CTRL_C1_MOD_CC1_AMP              29
#define CTRL_C1_MOD_CC1_LFO_PITCH        30
#define CTRL_C1_MOD_CC1_LFO_FILTER       31
#define CTRL_C1_MOD_CC1_LFO_AMP          32
#define CTRL_C1_MOD_CC2_PITCH            33
#define CTRL_C1_MOD_CC2_FILTER           34
#define CTRL_C1_MOD_CC2_AMP              35
#define CTRL_C1_MOD_CC2_LFO_PITCH        36
#define CTRL_C1_MOD_CC2_LFO_FILTER       37
#define CTRL_C1_MOD_CC2_LFO_AMP          38
#define CTRL_C1_KEY_LOWER                39
#define CTRL_C1_KEY_UPPER                40
#define CTRL_C2_EN                       41
#define CTRL_C2_VOL                      42
#define CTRL_C2_PAN                      43
#define CTRL_C2_PATCH                    44
#define CTRL_C2_REV_SEND                 45
#define CTRL_C2_CHO_SEND                 46
#define CTRL_C2_FT                       47
#define CTRL_C2_VIB_RATE                 48
#define CTRL_C2_VIB_DEPTH                49
#define CTRL_C2_VIB_DELAY                50
#define CTRL_C2_FILTER_CUTOFF            51
#define CTRL_C2_FILTER_RES               52
#define CTRL_C2_ENV_ATTACK               53
#define CTRL_C2_ENV_DECAY                54
#define CTRL_C2_ENV_RELEASE              55
#define CTRL_C2_MOD_BEND_PITCH           56
#define CTRL_C2_MOD_BEND_FILTER          57
#define CTRL_C2_MOD_BEND_AMP             58
#define CTRL_C2_MOD_BEND_LFO_PITCH       59
#define CTRL_C2_MOD_BEND_LFO_FILTER      60
#define CTRL_C2_MOD_BEND_LFO_AMP         61
#define CTRL_C2_MOD_WHEEL_PITCH          62
#define CTRL_C2_MOD_WHEEL_FILTER         63
#define CTRL_C2_MOD_WHEEL_AMP            64
#define CTRL_C2_MOD_WHEEL_LFO_PITCH      65
#define CTRL_C2_MOD_WHEEL_LFO_FILTER     66
#define CTRL_C2_MOD_WHEEL_LFO_AMP        67
#define CTRL_C2_MOD_CC1_PITCH            68
#define CTRL_C2_MOD_CC1_FILTER           69
#define CTRL_C2_MOD_CC1_AMP              70
#define CTRL_C2_MOD_CC1_LFO_PITCH        71
#define CTRL_C2_MOD_CC1_LFO_FILTER       72
#define CTRL_C2_MOD_CC1_LFO_AMP          73
#define CTRL_C2_MOD_CC2_PITCH            74
#define CTRL_C2_MOD_CC2_FILTER           75
#define CTRL_C2_MOD_CC2_AMP              76
#define CTRL_C2_MOD_CC2_LFO_PITCH        77
#define CTRL_C2_MOD_CC2_LFO_FILTER       78
#define CTRL_C2_MOD_CC2_LFO_AMP          79
#define CTRL_C2_KEY_LOWER                80
#define CTRL_C2_KEY_UPPER                81
#define CTRL_C3_EN                       82
#define CTRL_C3_VOL                      83
#define CTRL_C3_PAN                      84
#define CTRL_C3_PATCH                    85
#define CTRL_C3_REV_SEND                 86
#define CTRL_C3_CHO_SEND                 87
#define CTRL_C3_FT                       88
#define CTRL_C3_VIB_RATE                 89
#define CTRL_C3_VIB_DEPTH                90
#define CTRL_C3_VIB_DELAY                91
#define CTRL_C3_FILTER_CUTOFF            92
#define CTRL_C3_FILTER_RES               93
#define CTRL_C3_ENV_ATTACK               94
#define CTRL_C3_ENV_DECAY                95
#define CTRL_C3_ENV_RELEASE              96
#define CTRL_C3_MOD_BEND_PITCH           97
#define CTRL_C3_MOD_BEND_FILTER          98
#define CTRL_C3_MOD_BEND_AMP             99
#define CTRL_C3_MOD_BEND_LFO_PITCH       100
#define CTRL_C3_MOD_BEND_LFO_FILTER      101
#define CTRL_C3_MOD_BEND_LFO_AMP         102
#define CTRL_C3_MOD_WHEEL_PITCH          103
#define CTRL_C3_MOD_WHEEL_FILTER         104
#define CTRL_C3_MOD_WHEEL_AMP            105
#define CTRL_C3_MOD_WHEEL_LFO_PITCH      106
#define CTRL_C3_MOD_WHEEL_LFO_FILTER     107
#define CTRL_C3_MOD_WHEEL_LFO_AMP        108
#define CTRL_C3_MOD_CC1_PITCH            109
#define CTRL_C3_MOD_CC1_FILTER           110
#define CTRL_C3_MOD_CC1_AMP              111
#define CTRL_C3_MOD_CC1_LFO_PITCH        112
#define CTRL_C3_MOD_CC1_LFO_FILTER       113
#define CTRL_C3_MOD_CC1_LFO_AMP          114
#define CTRL_C3_MOD_CC2_PITCH            115
#define CTRL_C3_MOD_CC2_FILTER           116
#define CTRL_C3_MOD_CC2_AMP              117
#define CTRL_C3_MOD_CC2_LFO_PITCH        118
#define CTRL_C3_MOD_CC2_LFO_FILTER       119
#define CTRL_C3_MOD_CC2_LFO_AMP          120
#define CTRL_C3_KEY_LOWER                121
#define CTRL_C3_KEY_UPPER                122
#define CTRL_REV_TYPE                    123
#define CTRL_REV_VOL                     124
#define CTRL_REV_TIME                    125
#define CTRL_REV_FB                      126
#define CTRL_CHO_TYPE                    127
#define CTRL_CHO_VOL                     128
#define CTRL_CHO_DEL                     129
#define CTRL_CHO_FB                      130
#define CTRL_CHO_RATE                    131
#define CTRL_CHO_DEPTH                   132
#define CTRL_MSTR_VOL                    133
#define CTRL_MSTR_TEMPO                  134
#define CTRL_MSTR_QUANT                  135
#define CTRL_MOD_LFO_RATE                136
#define CTRL_MSTR_TUNING                 137
#define CTRL_MSTR_SCALE                  138
#define CTRL_DRUM_EN                     139
#define CTRL_DRUM_KIT                    140
#define CTRL_DRUM_PAT0                   141
#define CTRL_DRUM_PAT1                   142S
#define CTRL_DRUM_PAT2                   143
#define CTRL_DRUM_PAT3                   144
#define CTRL_DRUM_CHO_SEND               145
#define CTRL_DRUM_REV_SEND               146
#define CTRL_ARP_EN                      147
#define CTRL_ARP_PAT                     148


#define ACTION_SAVE                      0
#define ACTION_RESTORE                   1
#define ACTION_RESET                     2


/* Array of default control values */
const char control_defaults[149] = {
  1,
  127,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  66,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  10,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  0,
  26,
  0,
  127,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  66,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  10,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  0,
  26,
  0,
  127,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  64,
  66,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  10,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  64,
  64,
  64,
  0,
  0,
  0,
  0,
  26,
  4,
  10,
  80,
  0,
  2,
  90,
  40,
  7,
  9,
  13,
  127,
  100,
  0,
  40,
  0,
  0,
  0,
  0,
  0,
  1,
  2,
  3,
  0,
  0,
  0,
  0,
};

/* Array of default control values */
const char control_types[149] = {
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  3,
  3,
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  3,
  3,
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  3,
  3,
  4,
  1,
  1,
  1,
  5,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  6,
  1,
  1,
  7,
  0,
  8,
  9,
  9,
  9,
  9,
  1,
  1,
  0,
  10,
};

/* ------------------ The menu structure ----------------- */
/*  0    :      7 |      8 |     -1 | Channel options      */
/*  1    :     -1 |    192 |     -1 | Effects              */
/*  2    :     -1 |    207 |     -1 | General              */
/*  3    :     -1 |    214 |     -1 | Drums                */
/*  4    :     -1 |    223 |     -1 | Arpegiator           */
/*  5    :     -1 |     -2 |      0 | Save                 */
/*  6    :     -1 |     -2 |      1 | Restore              */
/*  7    :      0 |     -2 |      2 | Reset                */
/*  8    :     11 |     12 |     -1 | Channel 1            */
/*  9    :     -1 |     72 |     -1 | Channel 2            */
/*  10   :     -1 |    132 |     -1 | Channel 3            */
/*  11   :      8 |     -3 |     -1 | Back                 */
/*  12   :     24 |     -1 |      0 | Enable               */
/*  13   :     -1 |     -1 |      1 | Volume               */
/*  14   :     -1 |     -1 |      2 | Pan                  */
/*  15   :     -1 |     -1 |      3 | Patch                */
/*  16   :     -1 |     -1 |      4 | Reverb send          */
/*  17   :     -1 |     -1 |      5 | Chorus send          */
/*  18   :     -1 |     -1 |      6 | Fine tune            */
/*  19   :     -1 |     25 |     -1 | Vibrate              */
/*  20   :     -1 |     29 |     -1 | Filter               */
/*  21   :     -1 |     32 |     -1 | Envelope             */
/*  22   :     -1 |     36 |     -1 | Modulation           */
/*  23   :     -1 |     69 |     -1 | Key range            */
/*  24   :     12 |     -3 |     -1 | Back                 */
/*  25   :     28 |     -1 |      7 | Rate                 */
/*  26   :     -1 |     -1 |      8 | Depth                */
/*  27   :     -1 |     -1 |      9 | Delay                */
/*  28   :     25 |     -3 |     -1 | Back                 */
/*  29   :     31 |     -1 |     10 | Cutoff               */
/*  30   :     -1 |     -1 |     11 | Resonance            */
/*  31   :     29 |     -3 |     -1 | Back                 */
/*  32   :     35 |     -1 |     12 | Attack               */
/*  33   :     -1 |     -1 |     13 | Decay                */
/*  34   :     -1 |     -1 |     14 | Release              */
/*  35   :     32 |     -3 |     -1 | Back                 */
/*  36   :     40 |     41 |     -1 | Pitch bend           */
/*  37   :     -1 |     48 |     -1 | Mod wheel            */
/*  38   :     -1 |     55 |     -1 | CC1                  */
/*  39   :     -1 |     62 |     -1 | CC2                  */
/*  40   :     36 |     -3 |     -1 | Back                 */
/*  41   :     47 |     -1 |     15 | Pitch                */
/*  42   :     -1 |     -1 |     16 | Filter cutoff        */
/*  43   :     -1 |     -1 |     17 | Amplitude            */
/*  44   :     -1 |     -1 |     18 | LFO pitch depth      */
/*  45   :     -1 |     -1 |     19 | LFO filter depth     */
/*  46   :     -1 |     -1 |     20 | LFO amplitude depth  */
/*  47   :     41 |     -3 |     -1 | Back                 */
/*  48   :     54 |     -1 |     21 | Pitch                */
/*  49   :     -1 |     -1 |     22 | Filter cutoff        */
/*  50   :     -1 |     -1 |     23 | Amplitude            */
/*  51   :     -1 |     -1 |     24 | LFO pitch depth      */
/*  52   :     -1 |     -1 |     25 | LFO filter depth     */
/*  53   :     -1 |     -1 |     26 | LFO amplitude depth  */
/*  54   :     48 |     -3 |     -1 | Back                 */
/*  55   :     61 |     -1 |     27 | Pitch                */
/*  56   :     -1 |     -1 |     28 | Filter cutoff        */
/*  57   :     -1 |     -1 |     29 | Amplitude            */
/*  58   :     -1 |     -1 |     30 | LFO pitch depth      */
/*  59   :     -1 |     -1 |     31 | LFO filter depth     */
/*  60   :     -1 |     -1 |     32 | LFO amplitude depth  */
/*  61   :     55 |     -3 |     -1 | Back                 */
/*  62   :     68 |     -1 |     33 | Pitch                */
/*  63   :     -1 |     -1 |     34 | Filter cutoff        */
/*  64   :     -1 |     -1 |     35 | Amplitude            */
/*  65   :     -1 |     -1 |     36 | LFO pitch depth      */
/*  66   :     -1 |     -1 |     37 | LFO filter depth     */
/*  67   :     -1 |     -1 |     38 | LFO amplitude depth  */
/*  68   :     62 |     -3 |     -1 | Back                 */
/*  69   :     71 |     -1 |     39 | Lower                */
/*  70   :     -1 |     -1 |     40 | Upper                */
/*  71   :     69 |     -3 |     -1 | Back                 */
/*  72   :     84 |     -1 |     41 | Enable               */
/*  73   :     -1 |     -1 |     42 | Volume               */
/*  74   :     -1 |     -1 |     43 | Pan                  */
/*  75   :     -1 |     -1 |     44 | Patch                */
/*  76   :     -1 |     -1 |     45 | Reverb send          */
/*  77   :     -1 |     -1 |     46 | Chorus send          */
/*  78   :     -1 |     -1 |     47 | Fine tune            */
/*  79   :     -1 |     85 |     -1 | Vibrate              */
/*  80   :     -1 |     89 |     -1 | Filter               */
/*  81   :     -1 |     92 |     -1 | Envelope             */
/*  82   :     -1 |     96 |     -1 | Modulation           */
/*  83   :     -1 |    129 |     -1 | Key range            */
/*  84   :     72 |     -3 |     -1 | Back                 */
/*  85   :     88 |     -1 |     48 | Rate                 */
/*  86   :     -1 |     -1 |     49 | Depth                */
/*  87   :     -1 |     -1 |     50 | Delay                */
/*  88   :     85 |     -3 |     -1 | Back                 */
/*  89   :     91 |     -1 |     51 | Cutoff               */
/*  90   :     -1 |     -1 |     52 | Resonance            */
/*  91   :     89 |     -3 |     -1 | Back                 */
/*  92   :     95 |     -1 |     53 | Attack               */
/*  93   :     -1 |     -1 |     54 | Decay                */
/*  94   :     -1 |     -1 |     55 | Release              */
/*  95   :     92 |     -3 |     -1 | Back                 */
/*  96   :    100 |    101 |     -1 | Pitch bend           */
/*  97   :     -1 |    108 |     -1 | Mod wheel            */
/*  98   :     -1 |    115 |     -1 | CC1                  */
/*  99   :     -1 |    122 |     -1 | CC2                  */
/*  100  :     96 |     -3 |     -1 | Back                 */
/*  101  :    107 |     -1 |     56 | Pitch                */
/*  102  :     -1 |     -1 |     57 | Filter cutoff        */
/*  103  :     -1 |     -1 |     58 | Amplitude            */
/*  104  :     -1 |     -1 |     59 | LFO pitch depth      */
/*  105  :     -1 |     -1 |     60 | LFO filter depth     */
/*  106  :     -1 |     -1 |     61 | LFO amplitude depth  */
/*  107  :    101 |     -3 |     -1 | Back                 */
/*  108  :    114 |     -1 |     62 | Pitch                */
/*  109  :     -1 |     -1 |     63 | Filter cutoff        */
/*  110  :     -1 |     -1 |     64 | Amplitude            */
/*  111  :     -1 |     -1 |     65 | LFO pitch depth      */
/*  112  :     -1 |     -1 |     66 | LFO filter depth     */
/*  113  :     -1 |     -1 |     67 | LFO amplitude depth  */
/*  114  :    108 |     -3 |     -1 | Back                 */
/*  115  :    121 |     -1 |     68 | Pitch                */
/*  116  :     -1 |     -1 |     69 | Filter cutoff        */
/*  117  :     -1 |     -1 |     70 | Amplitude            */
/*  118  :     -1 |     -1 |     71 | LFO pitch depth      */
/*  119  :     -1 |     -1 |     72 | LFO filter depth     */
/*  120  :     -1 |     -1 |     73 | LFO amplitude depth  */
/*  121  :    115 |     -3 |     -1 | Back                 */
/*  122  :    128 |     -1 |     74 | Pitch                */
/*  123  :     -1 |     -1 |     75 | Filter cutoff        */
/*  124  :     -1 |     -1 |     76 | Amplitude            */
/*  125  :     -1 |     -1 |     77 | LFO pitch depth      */
/*  126  :     -1 |     -1 |     78 | LFO filter depth     */
/*  127  :     -1 |     -1 |     79 | LFO amplitude depth  */
/*  128  :    122 |     -3 |     -1 | Back                 */
/*  129  :    131 |     -1 |     80 | Lower                */
/*  130  :     -1 |     -1 |     81 | Upper                */
/*  131  :    129 |     -3 |     -1 | Back                 */
/*  132  :    144 |     -1 |     82 | Enable               */
/*  133  :     -1 |     -1 |     83 | Volume               */
/*  134  :     -1 |     -1 |     84 | Pan                  */
/*  135  :     -1 |     -1 |     85 | Patch                */
/*  136  :     -1 |     -1 |     86 | Reverb send          */
/*  137  :     -1 |     -1 |     87 | Chorus send          */
/*  138  :     -1 |     -1 |     88 | Fine tune            */
/*  139  :     -1 |    145 |     -1 | Vibrate              */
/*  140  :     -1 |    149 |     -1 | Filter               */
/*  141  :     -1 |    152 |     -1 | Envelope             */
/*  142  :     -1 |    156 |     -1 | Modulation           */
/*  143  :     -1 |    189 |     -1 | Key range            */
/*  144  :    132 |     -3 |     -1 | Back                 */
/*  145  :    148 |     -1 |     89 | Rate                 */
/*  146  :     -1 |     -1 |     90 | Depth                */
/*  147  :     -1 |     -1 |     91 | Delay                */
/*  148  :    145 |     -3 |     -1 | Back                 */
/*  149  :    151 |     -1 |     92 | Cutoff               */
/*  150  :     -1 |     -1 |     93 | Resonance            */
/*  151  :    149 |     -3 |     -1 | Back                 */
/*  152  :    155 |     -1 |     94 | Attack               */
/*  153  :     -1 |     -1 |     95 | Decay                */
/*  154  :     -1 |     -1 |     96 | Release              */
/*  155  :    152 |     -3 |     -1 | Back                 */
/*  156  :    160 |    161 |     -1 | Pitch bend           */
/*  157  :     -1 |    168 |     -1 | Mod wheel            */
/*  158  :     -1 |    175 |     -1 | CC1                  */
/*  159  :     -1 |    182 |     -1 | CC2                  */
/*  160  :    156 |     -3 |     -1 | Back                 */
/*  161  :    167 |     -1 |     97 | Pitch                */
/*  162  :     -1 |     -1 |     98 | Filter cutoff        */
/*  163  :     -1 |     -1 |     99 | Amplitude            */
/*  164  :     -1 |     -1 |    100 | LFO pitch depth      */
/*  165  :     -1 |     -1 |    101 | LFO filter depth     */
/*  166  :     -1 |     -1 |    102 | LFO amplitude depth  */
/*  167  :    161 |     -3 |     -1 | Back                 */
/*  168  :    174 |     -1 |    103 | Pitch                */
/*  169  :     -1 |     -1 |    104 | Filter cutoff        */
/*  170  :     -1 |     -1 |    105 | Amplitude            */
/*  171  :     -1 |     -1 |    106 | LFO pitch depth      */
/*  172  :     -1 |     -1 |    107 | LFO filter depth     */
/*  173  :     -1 |     -1 |    108 | LFO amplitude depth  */
/*  174  :    168 |     -3 |     -1 | Back                 */
/*  175  :    181 |     -1 |    109 | Pitch                */
/*  176  :     -1 |     -1 |    110 | Filter cutoff        */
/*  177  :     -1 |     -1 |    111 | Amplitude            */
/*  178  :     -1 |     -1 |    112 | LFO pitch depth      */
/*  179  :     -1 |     -1 |    113 | LFO filter depth     */
/*  180  :     -1 |     -1 |    114 | LFO amplitude depth  */
/*  181  :    175 |     -3 |     -1 | Back                 */
/*  182  :    188 |     -1 |    115 | Pitch                */
/*  183  :     -1 |     -1 |    116 | Filter cutoff        */
/*  184  :     -1 |     -1 |    117 | Amplitude            */
/*  185  :     -1 |     -1 |    118 | LFO pitch depth      */
/*  186  :     -1 |     -1 |    119 | LFO filter depth     */
/*  187  :     -1 |     -1 |    120 | LFO amplitude depth  */
/*  188  :    182 |     -3 |     -1 | Back                 */
/*  189  :    191 |     -1 |    121 | Lower                */
/*  190  :     -1 |     -1 |    122 | Upper                */
/*  191  :    189 |     -3 |     -1 | Back                 */
/*  192  :    194 |    195 |     -1 | Reverb               */
/*  193  :     -1 |    200 |     -1 | Chorus               */
/*  194  :    192 |     -3 |     -1 | Back                 */
/*  195  :    199 |     -1 |    123 | Type                 */
/*  196  :     -1 |     -1 |    124 | Volume               */
/*  197  :     -1 |     -1 |    125 | Time                 */
/*  198  :     -1 |     -1 |    126 | Feedback             */
/*  199  :    195 |     -3 |     -1 | Back                 */
/*  200  :    206 |     -1 |    127 | Type                 */
/*  201  :     -1 |     -1 |    128 | Volume               */
/*  202  :     -1 |     -1 |    129 | Delay                */
/*  203  :     -1 |     -1 |    130 | Feedback             */
/*  204  :     -1 |     -1 |    131 | Rate                 */
/*  205  :     -1 |     -1 |    132 | Depth                */
/*  206  :    200 |     -3 |     -1 | Back                 */
/*  207  :    213 |     -1 |    133 | Master Volume        */
/*  208  :     -1 |     -1 |    134 | Tempo                */
/*  209  :     -1 |     -1 |    135 | Quantize             */
/*  210  :     -1 |     -1 |    136 | LFO Mod Wheel        */
/*  211  :     -1 |     -1 |    137 | Tuning               */
/*  212  :     -1 |     -1 |    138 | Scale                */
/*  213  :    207 |     -3 |     -1 | Back                 */
/*  214  :    222 |     -1 |    139 | Enable               */
/*  215  :     -1 |     -1 |    140 | Kit                  */
/*  216  :     -1 |     -1 |    141 | Pattern 1            */
/*  217  :     -1 |     -1 |    142 | Pattern 2            */
/*  218  :     -1 |     -1 |    143 | Pattern 3            */
/*  219  :     -1 |     -1 |    144 | Pattern 4            */
/*  220  :     -1 |     -1 |    145 | Chorus send          */
/*  221  :     -1 |     -1 |    146 | Reverb send          */
/*  222  :    214 |     -3 |     -1 | Back                 */
/*  223  :    225 |     -1 |    147 | Enable               */
/*  224  :     -1 |     -1 |    148 | Pattern              */
/*  225  :    223 |     -3 |     -1 | Back                 */
/* ------------------------------------------------------- */

const short menu_dir[] = {
  7,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  0,
  11,
  -1,
  -1,
  8,
  24,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  12,
  28,
  -1,
  -1,
  25,
  31,
  -1,
  29,
  35,
  -1,
  -1,
  32,
  40,
  -1,
  -1,
  -1,
  36,
  47,
  -1,
  -1,
  -1,
  -1,
  -1,
  41,
  54,
  -1,
  -1,
  -1,
  -1,
  -1,
  48,
  61,
  -1,
  -1,
  -1,
  -1,
  -1,
  55,
  68,
  -1,
  -1,
  -1,
  -1,
  -1,
  62,
  71,
  -1,
  69,
  84,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  72,
  88,
  -1,
  -1,
  85,
  91,
  -1,
  89,
  95,
  -1,
  -1,
  92,
  100,
  -1,
  -1,
  -1,
  96,
  107,
  -1,
  -1,
  -1,
  -1,
  -1,
  101,
  114,
  -1,
  -1,
  -1,
  -1,
  -1,
  108,
  121,
  -1,
  -1,
  -1,
  -1,
  -1,
  115,
  128,
  -1,
  -1,
  -1,
  -1,
  -1,
  122,
  131,
  -1,
  129,
  144,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  132,
  148,
  -1,
  -1,
  145,
  151,
  -1,
  149,
  155,
  -1,
  -1,
  152,
  160,
  -1,
  -1,
  -1,
  156,
  167,
  -1,
  -1,
  -1,
  -1,
  -1,
  161,
  174,
  -1,
  -1,
  -1,
  -1,
  -1,
  168,
  181,
  -1,
  -1,
  -1,
  -1,
  -1,
  175,
  188,
  -1,
  -1,
  -1,
  -1,
  -1,
  182,
  191,
  -1,
  189,
  194,
  -1,
  192,
  199,
  -1,
  -1,
  -1,
  195,
  206,
  -1,
  -1,
  -1,
  -1,
  -1,
  200,
  213,
  -1,
  -1,
  -1,
  -1,
  -1,
  207,
  222,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  214,
  225,
  -1,
  223,
};

const char menu_sel[] = {
  8,
  192,
  207,
  214,
  223,
  -2,
  -2,
  -2,
  12,
  72,
  132,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  25,
  29,
  32,
  36,
  69,
  -3,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -3,
  41,
  48,
  55,
  62,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  85,
  89,
  92,
  96,
  129,
  -3,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -3,
  101,
  108,
  115,
  122,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  145,
  149,
  152,
  156,
  189,
  -3,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -3,
  161,
  168,
  175,
  182,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
  195,
  200,
  -3,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -3,
  -1,
  -1,
  -3,
};

const char menu_ctrl[] = {
  -1,
  -1,
  -1,
  -1,
  -1,
  0,
  1,
  2,
  -1,
  -1,
  -1,
  -1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  7,
  8,
  9,
  -1,
  10,
  11,
  -1,
  12,
  13,
  14,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  15,
  16,
  17,
  18,
  19,
  20,
  -1,
  21,
  22,
  23,
  24,
  25,
  26,
  -1,
  27,
  28,
  29,
  30,
  31,
  32,
  -1,
  33,
  34,
  35,
  36,
  37,
  38,
  -1,
  39,
  40,
  -1,
  41,
  42,
  43,
  44,
  45,
  46,
  47,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  48,
  49,
  50,
  -1,
  51,
  52,
  -1,
  53,
  54,
  55,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  56,
  57,
  58,
  59,
  60,
  61,
  -1,
  62,
  63,
  64,
  65,
  66,
  67,
  -1,
  68,
  69,
  70,
  71,
  72,
  73,
  -1,
  74,
  75,
  76,
  77,
  78,
  79,
  -1,
  80,
  81,
  -1,
  82,
  83,
  84,
  85,
  86,
  87,
  88,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  89,
  90,
  91,
  -1,
  92,
  93,
  -1,
  94,
  95,
  96,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  97,
  98,
  99,
  100,
  101,
  102,
  -1,
  103,
  104,
  105,
  106,
  107,
  108,
  -1,
  109,
  110,
  111,
  112,
  113,
  114,
  -1,
  115,
  116,
  117,
  118,
  119,
  120,
  -1,
  121,
  122,
  -1,
  -1,
  -1,
  -1,
  123,
  124,
  125,
  126,
  -1,
  127,
  128,
  129,
  130,
  131,
  132,
  -1,
  133,
  134,
  135,
  136,
  137,
  138,
  -1,
  139,
  140,
  141,
  142,
  143,
  144,
  145,
  146,
  -1,
  147,
  148,
  -1,
};

const char menu_ctrl_types[] = {
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  -1,
  1,
  1,
  -1,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  3,
  3,
  -1,
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  -1,
  1,
  1,
  -1,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  3,
  3,
  -1,
  0,
  1,
 1,
  2,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  -1,
  1,
  1,
  -1,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  1,
  1,
  1,
  1,
  -1,
  3,
  3,
  -1,
  -1,
  -1,
  -1,
  4,
  1,
  1,
  1,
  -1,
  5,
  1,
  1,
  1,
  1,
  1,
  -1,
  1,
  1,
  6,
  1,
  1,
  7,
  -1,
  0,
  8,
  9,
  9,
  9,
  9,
  1,
  1,
  -1,
  0,
  10,
  -1,
};

const char* menu_str[] = {
  "Channel options",
  "Effects",
  "General",
  "Drums",
  "Arpegiator",
  "Save",
  "Restore",
  "Reset",
  "Channel 1",
  "Channel 2",
  "Channel 3",
  "Back",
  "Enable",
  "Volume",
  "Pan",
  "Patch",
  "Reverb send",
  "Chorus send",
  "Fine tune",
  "Vibrate",
  "Filter",
  "Envelope",
  "Modulation",
  "Key range",
  "Back",
  "Rate",
  "Depth",
  "Delay",
  "Back",
  "Cutoff",
  "Resonance",
  "Back",
  "Attack",
  "Decay",
  "Release",
  "Back",
  "Pitch bend",
  "Mod wheel",
  "CC1",
  "CC2",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Lower",
  "Upper",
  "Back",
  "Enable",
  "Volume",
  "Pan",
  "Patch",
  "Reverb send",
  "Chorus send",
  "Fine tune",
  "Vibrate",
  "Filter",
  "Envelope",
  "Modulation",
  "Key range",
  "Back",
  "Rate",
  "Depth",
  "Delay",
  "Back",
  "Cutoff",
  "Resonance",
  "Back",
  "Attack",
  "Decay",
  "Release",
  "Back",
  "Pitch bend",
  "Mod wheel",
  "CC1",
  "CC2",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Lower",
  "Upper",
  "Back",
  "Enable",
  "Volume",
  "Pan",
  "Patch",
  "Reverb send",
  "Chorus send",
  "Fine tune",
  "Vibrate",
  "Filter",
  "Envelope",
  "Modulation",
  "Key range",
  "Back",
  "Rate",
  "Depth",
  "Delay",
  "Back",
  "Cutoff",
  "Resonance",
  "Back",
  "Attack",
  "Decay",
  "Release",
  "Back",
  "Pitch bend",
  "Mod wheel",
  "CC1",
  "CC2",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Pitch",
  "Filter cutoff",
  "Amplitude",
  "LFO pitch depth",
  "LFO filter depth",
  "LFO amplitude depth",
  "Back",
  "Lower",
  "Upper",
  "Back",
  "Reverb",
  "Chorus",
  "Back",
  "Type",
  "Volume",
  "Time",
  "Feedback",
  "Back",
  "Type",
  "Volume",
  "Delay",
  "Feedback",
  "Rate",
  "Depth",
  "Back",
  "Master Volume",
  "Tempo",
  "Quantize",
  "LFO Mod Wheel",
  "Tuning",
  "Scale",
  "Back",
  "Enable",
  "Kit",
  "Pattern 1",
  "Pattern 2",
  "Pattern 3",
  "Pattern 4",
  "Chorus send",
  "Reverb send",
  "Back",
  "Enable",
  "Pattern",
  "Back",
};
