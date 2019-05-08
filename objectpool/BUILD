cc_binary(
    name = "objectpool",
    deps = [
        ":objectpool_lib",
    ],
)
cc_library(
    name = "objectpool_lib",
    srcs = [
        "test/object_pool_test.cpp"
    ],
    hdrs = glob([
	    "include/**/*.h",
	    "test/*.h",
	]),
	includes = [
	    "include",
	    "test",
	],
    copts = [
    ],
    linkopts = [
        "-lgtest",
        "-lpthread",
    ],
)
