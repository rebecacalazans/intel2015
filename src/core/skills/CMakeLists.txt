set(SRCROOT ${PROJECT_SOURCE_DIR}/src/core/skills)

set (SRCS
     ${SRCROOT}/attack.cpp
     ${SRCROOT}/kick.cpp)

add_library(intel_skills ${SRCS})
