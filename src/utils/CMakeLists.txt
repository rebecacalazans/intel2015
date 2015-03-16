set(INCROOT ${PROJECT_SOURCE_DIR}/include/utils)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/utils)

set(SRCS
    ${INCROOT}/geom.h
    ${INCROOT}/steppable.h
    ${INCROOT}/point.h
    ${SRCROOT}/point.cpp
    ${INCROOT}/statemachine.h
    ${SRCROOT}/statemachine.cpp)

add_library(intel_utils ${SRCS})
