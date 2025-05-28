/*
 * A test for attempt to send a mutable signal.
 */

#include <so_5/all.hpp>

using namespace std;

int
main()
{
	try
	{
		so_5::launch(
			[&](so_5::environment_t & env) {
				struct demo final : public so_5::signal_t {};
				const auto mbox = env.create_mbox();

				so_5::send<so_5::mutable_msg<demo>>(mbox);
			} );
	}
	catch(const exception & ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}

	return 0;
}

