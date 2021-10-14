<?php
  $page_title = 'Home Page';
  require_once('includes/load.php');
  if (!$session->isUserLoggedIn(true)) { redirect('index.php', false);}
?>
<?php include_once('layouts/header.php'); ?>
<div class="row">
  <div class="col-md-12">
    <?php echo display_msg($msg); ?>
  </div>
 <div class="col-md-12">
    <div class="panel">
      <div class="jumbotron text-center">
         <h1>Welcome User <hr> Sales Management System</h1>
         <p>Browes around to find out the pages that you can access!</p>
      </div>
    </div>
 </div>
</div>
<?php include_once('layouts/footer.php'); ?>
