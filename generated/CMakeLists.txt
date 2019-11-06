add_custom_command(OUTPUT
    ${CMAKE_CURRENT_SOURCE_DIR}/Icu_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Icu_PBcfg.h
    DEPENDS ${ICU_CONFIG_FILEPATH}
    DEPENDS ${PROJECT_SOURCE_DIR}/script/source.c.jinja2
    DEPENDS ${PROJECT_SOURCE_DIR}/script/header.h.jinja2
    COMMAND bsw_code_gen
    -schema ${PROJECT_SOURCE_DIR}/config/icu.schema.json
    -template_directory ${PROJECT_SOURCE_DIR}/script
    ${ICU_CONFIG_FILEPATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/Icu_PBcfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Icu_PBcfg.h
    COMMENT "generating post-build configuration files")

add_library(Icu_PBcfg STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Icu_PBcfg.c)

target_include_directories(Icu_PBcfg
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${PROJECT_SOURCE_DIR}/interface
    PRIVATE ${AUTOSAR_STD_HEADER_PATH}
    PRIVATE $<$<BOOL:${ICU_ENABLE_TEST}>:${PROJECT_SOURCE_DIR}/test/stub>)
