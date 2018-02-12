<%@ Application Language="C#" %>
<%@ Import Namespace="SUEweb2" %>
<%@ Import Namespace="System.Web.Optimization" %>

<script runat="server">

    void Application_Start(object sender, EventArgs e)
    {
        BundleConfig.RegisterBundles(BundleTable.Bundles);
    }

</script>
