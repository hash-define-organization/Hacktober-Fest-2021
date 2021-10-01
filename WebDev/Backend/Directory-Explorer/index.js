const fs = require('fs');
const path = require('path');
const stdin = process.stdin;
const stdout = process.stdout;

fs.readdir(process.cwd(), (err, files) => {

	console.log('');

	if(!files.length)
	{
		return console.log('	\033[31m No Files to show!\033[39m\n');
	}

	console.log("	Select the files or directories you want to see\n");

	let stats = [];

	const file = (i) => {

		let filename = files[i];

		fs.stat(path.join(__dirname, filename), (err, stat) => {

			stats[i] = stat;

			if(stat.isDirectory())
			{
				console.log('	' + i + '	\033[36m' + filename + '/\033[39m');
			}
			else
			{
				console.log('	' + i + '	\033[90m' + filename + '\033[39m');
			}

			function read()
			{
				console.log('');

				stdout.write('	\033[33mEnter your Choice: \033[39m');
				stdin.resume();
				stdin.setEncoding('utf8');
				stdin.on('data', option);
			}

			function option(data)
			{

				if(!files[Number(data)])
				{
					stdout.write('	\033[33mEnter your Choice: \033[39m');
				}
				else
				{
					stdin.pause();

					if(stats[Number(data)].isDirectory())
					{
						fs.readdir(path.join(__dirname, files[Number(data)]), (err, files) => {

							console.log('');

							console.log('	(' + files.length + ' files)');

							files.forEach((file) => {

								console.log('	 - ' + file)

							});

							console.log('');

						});
					}
					else
					{
						fs.readFile(path.join(__dirname, files[Number(data)]), 'utf8', (err, data) => {

							console.log('');
							console.log('\033[90m' + data.replace(/(.*)/g, '	$1') + '\033[39m');

						});
					}
				}
			}

			if(++i == files.length)
			{
				read();
			}
			else
			{
				file(i);
			}

		});
	}


	file(0);

});