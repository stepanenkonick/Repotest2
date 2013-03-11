/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"
int globalstatus;
vuser_init()
{
	
	globalstatus = web_global_verification("Search=Body", "Text=Error", "Fail=Found",  LAST);
	if (globalstatus == LR_FAIL)
{
     lr_error_message("Error: %s", "Login Failed - Aborted VU");
     lr_abort();
}

return 0;
}
