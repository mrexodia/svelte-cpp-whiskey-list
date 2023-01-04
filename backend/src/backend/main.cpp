#include <iostream>
#include <cstdlib>

#include <httplib.h>

int main()
{
	using namespace httplib;

	Server svr;

	svr.Get("/data", [](const httplib::Request&, httplib::Response& res) {
		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_content(R"JSON({"drinks":[{"strDrink":"Allegheny","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/uwvyts1483387934.jpg","idDrink":"11021"},{"strDrink":"Bourbon Sour","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/dms3io1504366318.jpg","idDrink":"11147"},{"strDrink":"Brandon and Will's Coke Float","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/xspxyr1472719185.jpg","idDrink":"16447"},{"strDrink":"Irish Curdling Cow","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/yrhutv1503563730.jpg","idDrink":"16987"},{"strDrink":"John Collins","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/0t4bv71606854479.jpg","idDrink":"11580"},{"strDrink":"Kentucky B And B","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/sqxsxp1478820236.jpg","idDrink":"11602"},{"strDrink":"Kentucky Colonel","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/utqwpu1478820348.jpg","idDrink":"11604"},{"strDrink":"Manhattan","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/yk70e31606771240.jpg","idDrink":"11008"},{"strDrink":"Midnight Cowboy","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/vsxxwy1441208133.jpg","idDrink":"11766"},{"strDrink":"Mint Julep","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/squyyq1439907312.jpg","idDrink":"17206"},{"strDrink":"Mississippi Planters Punch","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/urpyqs1439907531.jpg","idDrink":"11786"},{"strDrink":"Old Fashioned","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/vrwquq1478252802.jpg","idDrink":"11001"},{"strDrink":"Raspberry Julep","strDrinkThumb":"https:\/\/www.thecocktaildb.com\/images\/media\/drink\/hyztmx1598719265.jpg","idDrink":"178333"}]})JSON", "application/json");
	});

	// Relevant resources:
	// https://stackoverflow.com/a/66555660
	// https://developer.chrome.com/blog/private-network-access-preflight/
	// https://wicg.github.io/private-network-access
	svr.Options(".*", [](const Request& req, Response& res) {
		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_header("Access-Control-Allow-Methods", "*");
		res.set_header("Access-Control-Request-Credentials", "true");
		res.set_header("Access-Control-Allow-Private-Network", "true");
		res.set_header("Access-Control-Allow-Headers", "*");
	});

	svr.listen("0.0.0.0", 8080);

	return EXIT_SUCCESS;
}
