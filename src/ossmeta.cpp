#include "ossmeta.h"

namespace alioss {
	namespace meta{
		oss_data_center_s oss_data_center[oss_data_center_count+1] =
		{
			{ "HangZhou","oss-cn-hangzhou" },
			{ "QingDao", "oss-cn-qingdao" },
			{ "BeiJing", "oss-cn-beijing" },
			{ "HongKong", "oss-cn-hongkong" },
			{ "ShenZhen", "oss-cn-shenzhen" },
			{nullptr, nullptr}
		};
	}
}
