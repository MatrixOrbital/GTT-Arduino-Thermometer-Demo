set(SRC 
			gtt_ext_types.c
			gtt_packet_builder.c
			gtt_parser.c
			gtt_text.c
			gtt_protocol.c
			gtt_events.c
)

set(HDR
			gtt_text.h
			gtt_parser.h
			gtt_protocol.h
)
include_directories(${CMAKE_SOURCE_DIR}/GTTClient)
add_library(GTTClient STATIC ${SRC} ${HDR})
