set(SRCROOT ${PROJECT_SOURCE_DIR}/src/utils)

set(SRCS
    ${SRCROOT}/point.cpp
    ${SRCROOT}/statemachine.cpp)

add_library(intel_utils ${SRCS})
