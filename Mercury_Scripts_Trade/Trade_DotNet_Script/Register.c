/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"
int status;

Register()
{
	
	lr_think_time(1);
	lr_start_transaction("Register");

	status = web_url("register.aspx",
		"URL=http://{Server}/TRADE/register.aspx",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t113.inf",
		"Mode=HTTP",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Register Failed - Aborted VU");
     lr_abort();
}
lr_end_transaction("Register", LR_AUTO);


lr_think_time(1);
	lr_start_transaction("Register_Submit");
	
	status = web_submit_data("register.aspx",
		"Action=http://{Server}/TRADE/register.aspx",
				"Method=POST",
		"RecContentType=text/html",
		"Referer=http://{Server}/TRADE/register.aspx",
		"Snapshot=t114.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=__EVENTTARGET", "Value=LinkRegister", ENDITEM,
		"Name=__EVENTARGUMENT", "Value=", ENDITEM,
		"Name=UserID", "Value=user{newuserid}", ENDITEM,
		"Name=OpenBalance", "Value=10000", ENDITEM,
		"Name=FullName", "Value=FirstName", ENDITEM,
        "Name=Email", "Value=user@company.com", ENDITEM,
		"Name=Address", "Value=314 145th Ave", ENDITEM,
		"Name=Password", "Value=xxx", ENDITEM,
		"Name=CreditCard", "Value=123-fake-ccnum-456", ENDITEM,
		"Name=ConfirmPassword", "Value=xxx", ENDITEM,
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Register Failed - Aborted VU");
     lr_abort();
}

  lr_end_transaction("Register_Submit", LR_AUTO);	return 0;


}
