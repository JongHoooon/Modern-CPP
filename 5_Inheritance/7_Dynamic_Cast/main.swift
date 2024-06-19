import Foundation

class Animal { 
  func speak() { 
    print("animal")
  }
}

class Cat: Animal { 
  override func speak() { 
    print("meow")
  }
}

do { 
  let cat = Cat()
  let ani = cat as Animal

  ani.speak();
}
