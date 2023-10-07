function onClickEvent() {
  let mycount = 1;
  alert("completed " + mycount + " exercise");
  mycount = nestedcall(mycount);
  alert("completed " + mycount + " exercise");
}

function nestedcall(count) {
  console.group("nestedcall");
  document.querySelector("body > ul > li:nth-child(1)").remove();
  console.log("reached nestedcall!");
  console.groupEnd("nestedcall");
  return count + 6;
}
