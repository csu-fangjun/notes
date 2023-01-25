class Author {
  let name: String
  // weak reference is required
  weak var post: Post?

  init(name: String) {self.name = name}
  deinit {print("Author deinit")}
}

class Post {
  let title: String

  var author: Author?
  init(title: String) {self.title = title}
  deinit {print("Post deinit")}
}

var author: Author? = Author(name: "John Snow")
var post: Post? = Post(title: "foo bar")
post?.author = author
author?.post = post

print(author?.post) // Optional(main.Post)
post = nil // Post deinit
print(author?.post) // nil
author = nil // Author deinit
