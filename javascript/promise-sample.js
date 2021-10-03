const p = new Promise((resolve, reject) => {
  resolve("hi");
});
p.then((data) => {
  console.log(data);
}).catch((err) => {
  console.log(err.message);
});
