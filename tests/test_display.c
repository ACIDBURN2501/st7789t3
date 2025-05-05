#include "unity.h"

#include "image_loader.h"

void
setUp(void)
{
}
void
tearDown(void)
{
}

void
test_image_loader_returns_error_with_null_buffer(void)
{
        int result = image_load_rgb565("assets/splash.png", NULL, 240, 320);
        TEST_ASSERT_EQUAL_INT_MESSAGE(-1, result,
                                      "Expected error for NULL buffer");
}

int
main(void)
{
        UNITY_BEGIN();
        RUN_TEST(test_image_loader_returns_error_with_null_buffer);
        return UNITY_END();
}
