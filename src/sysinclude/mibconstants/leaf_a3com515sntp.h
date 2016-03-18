#define LEAF_sntpState	1
#define VAL_sntpState_disable	0L
#define VAL_sntpState_enable 	1L
#define LEAF_sntpPrimaryServer	2
#define LEAF_sntpSecondaryServer	3
#define LEAF_sntpActiveServer	4
#define LEAF_sntpPollInterval3com	5
#define MIN_sntpPollInterval3com	64L
#define MAX_sntpPollInterval3com	86400L
#define LEAF_sntpTimeISO	6
#define SIZE_sntpTimeISO	19L
#define LEAF_timeZoneOffset	7
#define MIN_timeZoneOffset	-720L
#define MAX_timeZoneOffset	840L
#define LEAF_dstState	8
#define VAL_dstState_disable	0L
#define VAL_dstState_north_america	1L
#define VAL_dstState_europe_parts_of_asia	2L
#define VAL_dstState_australia	3L
#define VAL_dstState_new_zealand	4L
#define VAL_dstState_user_configured	5L
#define LEAF_dstStartDate	9
#define SIZE_dstStartDate	19L
#define LEAF_dstEndDate	10
#define SIZE_dstEndDate	19L