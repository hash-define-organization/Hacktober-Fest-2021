const UNCOMPLETED_LIST_BOOK_ID = "incompleteBookshelfList";
const COMPLETED_LIST_BOOK_ID = "completeBookshelfList";
const BOOK_ITEMID = "bookId";

function makeBook(bookTitle, bookAuthor, bookYear, isCompleted) {
  const textBookTitle = document.createElement("h2");
  textBookTitle.innerText = bookTitle;

  const textBookAuthor = document.createElement("h3");
  textBookAuthor.innerText = bookAuthor;

  const textBookYear = document.createElement("p");
  textBookYear.innerText = bookYear;

  const textContainer = document.createElement("div");
  textContainer.classList.add("inner");
  textContainer.append(textBookTitle, textBookAuthor, textBookYear);

  const container = document.createElement("div");
  container.classList.add("item", "shadow");
  container.append(textContainer);

  if (isCompleted) {
    container.append(createUndoButton(), createTrashButton());
  } else {
    container.append(createCheckButton(), createTrashButton());
  }

  return container;
}

function addBook() {
  const uncompletedBOOKList = document.getElementById(UNCOMPLETED_LIST_BOOK_ID);

  const inputBook = document.getElementById("title").value;
  const inputTitle = document.getElementById("author").value;
  const inputYear = document.getElementById("year").value;

  const book = makeBook(inputBook, inputTitle, inputYear, false);
  const bookObject = composeBookObject(inputBook, inputTitle, inputYear, false);

  book[BOOK_ITEMID] = bookObject.id;
  books.push(bookObject);

  uncompletedBOOKList.append(book);
  updateDataToStorage();
  Swal.fire("Good job!", "Berhasil Menambah data!", "success");
}

function createButton(buttonTypeClass, eventListener) {
  const button = document.createElement("button");
  button.classList.add(buttonTypeClass);
  button.addEventListener("click", function (event) {
    eventListener(event);
  });
  return button;
}

function addTaskToCompleted(taskElement) {
  const listCompleted = document.getElementById(COMPLETED_LIST_BOOK_ID);

  const taskBook = taskElement.querySelector(".inner > h2").innerText;
  const taskAuthor = taskElement.querySelector(".inner > h3").innerText;
  const taskYear = taskElement.querySelector(".inner > p").innerText;

  const newBook = makeBook(taskBook, taskAuthor, taskYear, true);
  const book = findBook(taskElement[BOOK_ITEMID]);

  book.isCompleted = true;
  newBook[BOOK_ITEMID] = book.id;

  listCompleted.append(newBook);
  taskElement.remove();

  updateDataToStorage();
}

function createCheckButton() {
  return createButton("check-button", function (event) {
    addTaskToCompleted(event.target.parentElement);
  });
}

function removeTaskFromCompleted(taskElement) {
  Swal.fire({
    title: "Hapus data!",
    text: "Yakin ingin menghapus data?",
    icon: "warning",
    showCancelButton: true,
    confirmButtonColor: "#3085d6",
    cancelButtonColor: "#d33",
    confirmButtonText: "Yes, delete it!",
  }).then((result) => {
    if (result.isConfirmed) {
      const bookPosition = findBookIndex(taskElement[BOOK_ITEMID]);
      books.splice(bookPosition, 1);

      taskElement.remove();
      updateDataToStorage();
      Swal.fire("Deleted!", "Telah menghapus data.", "success");
    }
  });
}

function createTrashButton() {
  return createButton("trash-button", function (event) {
    removeTaskFromCompleted(event.target.parentElement);
  });
}

function undoTaskFromCompleted(taskElement) {
  const listUncompleted = document.getElementById(UNCOMPLETED_LIST_BOOK_ID);

  const taskBook = taskElement.querySelector(".inner > h2").innerText;
  const taskAuthor = taskElement.querySelector(".inner > h3").innerText;
  const taskYear = taskElement.querySelector(".inner > p").innerText;

  const newBook = makeBook(taskBook, taskAuthor, taskYear, false);

  const book = findBook(taskElement[BOOK_ITEMID]);
  book.isCompleted = false;
  newBook[BOOK_ITEMID] = book.id;

  listUncompleted.append(newBook);
  taskElement.remove();

  updateDataToStorage();
}

function createUndoButton() {
  return createButton("undo-button", function (event) {
    undoTaskFromCompleted(event.target.parentElement);
  });
}

function refreshDataFromBooks() {
  const listUncompleted = document.getElementById(UNCOMPLETED_LIST_BOOK_ID);
  let listCompleted = document.getElementById(COMPLETED_LIST_BOOK_ID);

  for (book of books) {
    const newBook = makeBook(book.title, book.author, book.year, book.isCompleted);
    newBook[BOOK_ITEMID] = book.id;

    if (book.isCompleted) {
      listCompleted.append(newBook);
    } else {
      listUncompleted.append(newBook);
    }
  }
}
