class Animal {
  init() { 
    print("animal init")
  }
  deinit { 
    print("animal deinit")
  }
  func hi() {
    print("animal hi!")
  }
}

class Cat: Animal { 
  override init() { 
    super.init()
    print("cat init")   
  }
  deinit {
    print("cat deinit")
  }
  override func hi() { 
    print("cat hi!")
  }
}

do { 
  let cat: Animal = Cat()
  cat.hi()
}
