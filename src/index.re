
/* https://immense-river-25513.herokuapp.com/locations */
Fetcher.fetchGet(
  ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=data => {
  /* entry |. Fetcher.username */
  let locations =
    Array.map(
      entry => {
        Entry.username: Fetcher.username(entry),
        Entry.location: Fetcher.location(entry),
      },
      data,
    );

  ReactDOMRe.renderToElementWithId(<App locations />, "main");
});